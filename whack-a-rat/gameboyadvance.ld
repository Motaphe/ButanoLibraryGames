/* gameboyadvance.ld */

OUTPUT_ARCH(arm7tdmi)
ENTRY(_start)
SECTIONS
{
    . = 0x08000000;
    .text : { *(.text) }
    .rodata : { *(.rodata) }
    .data : { *(.data) }
    .bss : { *(.bss) }
}
