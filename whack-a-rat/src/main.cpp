#include "bn_core.h"
#include "bn_math.h"
#include "bn_fixed_point.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_items_paw.h"
#include "bn_sprite_items_rat_out_of_hole.h"
#include "bn_sprite_items_empty_hole.h"
#include "bn_sprite_items_whacked_rat.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_items_start_screen.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_font.h"
#include "common_variable_8x8_sprite_font.h" // Include this header
#include "bn_string.h"
#include "bn_sstream.h"
#include "bn_keypad.h"
#include "bn_random.h"
#include "bn_vector.h"
#include "bn_array.h"
#include "bn_log.h"
#include "bn_optional.h"
// #include "bn_music.h"
// #include "bn_sound.h"
// #include "bn_music_items.h"
// #include "bn_sound_items.h"

namespace
{
    const bn::array<bn::fixed_point, 6> hole_positions = {
        bn::fixed_point(-60, -20),
        bn::fixed_point(0, -20),
        bn::fixed_point(60, -20),
        bn::fixed_point(-60, 20),
        bn::fixed_point(0, 20),
        bn::fixed_point(60, 20)
    };

    void main_game();
    void game_over_screen(int final_score);
}

int main()
{
    bn::core::init();

    // Show the start screen background
    bn::regular_bg_ptr bg = bn::regular_bg_items::start_screen.create_bg(0, 0);

    // Wait for the player to press the A button to start
    while(!bn::keypad::a_pressed())
    {
        bn::core::update();
    }

    // Start the game
    main_game();

    return 0;
}

namespace
{
    void main_game()
    {
        // Game variables
        int score = 0;
        int remaining_time = 60 * 60; // 60 seconds at 60 FPS
        bn::random random;

        // Create paw sprite
        bn::sprite_ptr paw_sprite = bn::sprite_items::paw.create_sprite(0, 0);
        paw_sprite.set_visible(false);

        // Create rat sprites
        bn::array<bn::optional<bn::sprite_ptr>, 6> rat_sprites;
        bn::array<bool, 6> rat_visible = { false, false, false, false, false, false };
        for(int i = 0; i < 6; ++i)
        {
            rat_sprites[i] = bn::sprite_items::rat_out_of_hole.create_sprite(hole_positions[i]);
            rat_sprites[i]->set_visible(false);
        }

        // Create hole sprites
        bn::vector<bn::sprite_ptr, 6> hole_sprites;
        for(const bn::fixed_point& position : hole_positions)
        {
            hole_sprites.push_back(bn::sprite_items::empty_hole.create_sprite(position));
        }

        // Text generator using the common font
        bn::sprite_text_generator text_generator(common::variable_8x8_sprite_font);
        bn::vector<bn::sprite_ptr, 32> text_sprites;

        while(remaining_time > 0)
        {
            --remaining_time;

            // Handle input
            if(bn::keypad::a_pressed())
            {
                // Calculate the position based on keypad input
                bn::fixed x = 0;
                bn::fixed y = 0;

                if(bn::keypad::left_held())
                {
                    x -= 120;
                }
                if(bn::keypad::right_held())
                {
                    x += 120;
                }
                if(bn::keypad::up_held())
                {
                    y -= 80;
                }
                if(bn::keypad::down_held())
                {
                    y += 80;
                }

                paw_sprite.set_position(x, y);
                paw_sprite.set_visible(true);

                // bn::sound_items::whack.play(); // Commented out
            }
            else if(bn::keypad::a_released())
            {
                paw_sprite.set_visible(false);
            }

            // Spawn rats randomly
            if(random.get_int(60) == 0)
            {
                int hole_index = random.get_int(6);
                if(!rat_visible[hole_index])
                {
                    rat_visible[hole_index] = true;
                    rat_sprites[hole_index]->set_visible(true);
                }
            }

            // Check for collisions
            for(int i = 0; i < 6; ++i)
            {
                if(rat_visible[i])
                {
                    bn::fixed_point paw_position = paw_sprite.position();
                    bn::fixed_point rat_position = rat_sprites[i]->position();
                    bn::fixed dx = paw_position.x() - rat_position.x();
                    bn::fixed dy = paw_position.y() - rat_position.y();
                    bn::fixed distance_squared = dx * dx + dy * dy;
                    bn::fixed collision_distance = 16; // Adjust based on sprite sizes
                    if(distance_squared < collision_distance * collision_distance)
                    {
                        // Whack the rat
                        rat_sprites[i]->set_item(bn::sprite_items::whacked_rat);
                        rat_visible[i] = false;
                        score += 10;
                    }
                }
            }

            // Update score and time display
            text_sprites.clear();

            // Score text
            bn::string<32> score_text_string;
            bn::ostringstream score_text_stream(score_text_string);
            score_text_stream.append("Score: ");
            score_text_stream.append(bn::to_string<8>(score));
            text_generator.generate(-110, -70, score_text_string, text_sprites);

            // Time text
            bn::string<32> timer_text_string;
            bn::ostringstream timer_text_stream(timer_text_string);
            timer_text_stream.append("Time: ");
            timer_text_stream.append(bn::to_string<8>(remaining_time / 60));
            text_generator.generate(60, -70, timer_text_string, text_sprites);

            bn::core::update();
        }

        // Game over
        game_over_screen(score);
    }

    void game_over_screen(int final_score)
    {
        // Clear the screen
        bn::core::update();

        // Text generator using the common font
        bn::sprite_text_generator text_generator(common::variable_8x8_sprite_font);
        bn::vector<bn::sprite_ptr, 32> text_sprites;

        // Display "Game Over"
        text_generator.generate(0, -10, "Game Over", text_sprites);

        // Display final score
        bn::string<32> score_text_string;
        bn::ostringstream score_text_stream(score_text_string);
        score_text_stream.append("Final Score: ");
        score_text_stream.append(bn::to_string<8>(final_score));
        text_generator.generate(0, 10, score_text_string, text_sprites);

        // Wait for player input to restart or exit
        while(!bn::keypad::start_pressed())
        {
            bn::core::update();
        }
    }
}
