#---------------------------------------------------------------------------------------------------------------------
# Makefile for Whack-a-Rat Game
#---------------------------------------------------------------------------------------------------------------------

TARGET      :=  $(notdir $(CURDIR))
BUILD       :=  build
LIBBUTANO   :=  ../../butano
PYTHON      :=  python
SOURCES     :=  src ../../common/src
INCLUDES    :=  include ../../common/include
DATA        :=
GRAPHICS    :=  graphics ../../common/graphics
AUDIO       :=  audio ../../common/audio
DMGAUDIO    :=  dmg_audio ../../common/dmg_audio
ROMTITLE    :=  WHACK-A-RAT
ROMCODE     :=  WHRT
USERFLAGS   :=  
USERASFLAGS :=  
USERLDFLAGS :=  
USERLIBDIRS :=  
USERLIBS    :=  
USERBUILD   :=  
EXTTOOL     :=  

#---------------------------------------------------------------------------------------------------------------------
# Export absolute butano path:
#---------------------------------------------------------------------------------------------------------------------
ifndef LIBBUTANOABS
    export LIBBUTANOABS :=  $(realpath $(LIBBUTANO))
endif

#---------------------------------------------------------------------------------------------------------------------
# Include main makefile:
#---------------------------------------------------------------------------------------------------------------------
include $(LIBBUTANOABS)/butano.mak
