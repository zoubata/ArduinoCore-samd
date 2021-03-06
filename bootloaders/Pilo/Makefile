# Copyright (c) 2015 Atmel Corporation/Thibaut VIARD.  All right reserved.
# Copyright (c) 2015 Arduino LLC.  All right reserved.
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
# Begin Config ###############################
MSG_EXTENDED_LISTING  = Creating extended listing to \`$@\'.
MSG_SYMBOL_TABLE      = Creating symbol table to \`$@\'.

# -----------------------------------------------------------------------------
# SD Card support. This can also be set in the relevant board_definitions file.
# SDCARD_DISABLED, SDCARD_ENABLED
SDCARD?=SDCARD_DISABLED

# -----------------------------------------------------------------------------
# Boards definitions:
# MT_D21E_rev_A, MT_D21E_rev_B, MT_D11
# arduino_zero, arduino_mkrzero, arduino_mkr1000, arduino_mkrfox1200, genuino_mkr1000, genuino_zero, arduino_m0, arduino_m0_pro
# Generic_x21E, Generic_x21G, Generic_x21J, Generic_D11D14AM, Generic_D11D14AS, Generic_D11C14A
BOARD_ID?=MT_D21E_rev_B

# -----------------------------------------------------------------------------
# MCU definitions:
# SAMD21J: SAMD21J18A, SAMD21J17A, SAMD21J16A, SAMD21J15A
# SAMD21G: SAMD21G18A, SAMD21G17A, SAMD21G16A, SAMD21G15A
# SAMD21E: SAMD21E18A, SAMD21E17A, SAMD21E16A, SAMD21E15A
# SAML21J: SAML21J18B, SAML21J17B, SAML21J16B
# SAML21G: SAML21G18B, SAML21G17B, SAML21G16B
# SAML21E: SAML21E18B, SAML21E17B, SAML21E16B, SAML21E15B
# SAMC21J: SAMC21J18A, SAMC21J17A, SAMC21J16A, SAMC21J15A
# SAMC21G: SAMC21G18A, SAMC21G17A, SAMC21G16A, SAMC21G15A
# SAMC21E: SAMC21E18A, SAMC21E17A, SAMC21E16A, SAMC21E15A
# SAMD11:  SAMD11D14AM, SAMD11C14A, SAMD11D14AS
MCU?=SAMD21E18A

# Note that the makefile can be invoked with values that override the above two settings.
# For example: BOARD_ID=Generic_D11C14A MCU=SAMD11C14A make

# End Config ###############################

ifeq ($(findstring ENABLED,$(SDCARD)),ENABLED)
NAME=sam_ba_sdcard_$(BOARD_ID)_$(MCU)
else
NAME=sam_ba_$(BOARD_ID)_$(MCU)_$(BOOT)
endif
BOOTSIZE=8KB

ifeq ($(findstring 18,$(MCU)),18)
FLASHSIZE=256KB
endif
ifeq ($(findstring 17,$(MCU)),17)
FLASHSIZE=128KB
endif
ifeq ($(findstring 16,$(MCU)),16)
FLASHSIZE=64KB
endif
ifeq ($(findstring 15,$(MCU)),15)
FLASHSIZE=32KB
endif
ifeq ($(findstring 14,$(MCU)),14)
FLASHSIZE=16KB
endif
ifeq ($(findstring D21,$(MCU)),D21)
BOOTSIZE=16KB
endif

LINKER_SCRIPT?=bootloader_sam_m0p_$(BOOTSIZE)_$(FLASHSIZE).ld

# CORE_VENDOR?=arduino
CORE_VENDOR?=zoubworld_Arduino

# -----------------------------------------------------------------------------
# Paths
ifeq ($(OS),Windows_NT)
  # Are we using mingw/msys/msys2/cygwin?
  ifeq ($(TERM),xterm)
  ifeq ($(HOSTNAME),zouba)
    T=$(shell cygpath -w $(shell pwd)/../../../../../../../..)
	else  
	ifeq ($(HOSTNAME),NAN-LT-M43507B)
    T=$(shell cygpath -w $(shell pwd)/../../../../../../../..)
	else
    T=$(shell cygpath -w $(LOCALAPPDATA))
	endif
	
	endif
	
    MODULE_PATH?=$(T)Arduino15/packages/$(CORE_VENDOR)
    MODULE_PATH_ARDUINO?=$(T)/Arduino15/packages/arduino
    RM=rm
    SEP=/
else ifeq ($(TERM),cygwin)
    T=$(shell cygpath -u $(LOCALAPPDATA))
    MODULE_PATH?=$(T)/Arduino15/packages/$(CORE_VENDOR)
    MODULE_PATH_ARDUINO?=$(T)/Arduino15/packages/arduino
    RM=rm
    SEP=/
  else
#    T=/cygdrive/c/temp/arduino
#    T=C:\temp\arduino
    T=$(shell cygpath -w $(LOCALAPPDATA))
#    T=$(LOCALAPPDATA)

    MODULE_PATH?=$(T)/Arduino15/packages/$(CORE_VENDOR)
    MODULE_PATH_ARDUINO?=$(T)/Arduino15/packages/arduino

    RM=rm
    SEP=\\
  endif
else
  UNAME_S := $(shell uname -s)

  ifeq ($(UNAME_S),Linux)
    MODULE_PATH?=$(HOME)/.arduino15/packages/$(CORE_VENDOR)
    MODULE_PATH_ARDUINO?=$(HOME)/.arduino15/packages/arduino
    RM=rm
    SEP=/
  endif

  ifeq ($(UNAME_S),Darwin)
    MODULE_PATH?=$(HOME)/Library/Arduino15/packages/$(CORE_VENDOR)/
    MODULE_PATH_ARDUINO?=$(HOME)/Library/Arduino15/packages/arduino/
    RM=rm
    SEP=/
  endif
endif



ifeq ($(HOSTNAME),zouba)
REV_ARCH=src
REV_CMSIS=src
else 
ifeq ($(HOSTNAME),NAN-LT-M43507B)
REV_ARCH=src
REV_CMSIS=src
else
REV_ARCH=1.6.19
REV_CMSIS=1.1.1-Zoubworld
endif
endif

PATHSEP=$(strip $(SEP))
ARM_GCC_PATH?=$(MODULE_PATH_ARDUINO)/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-
BUILD_DIR=build

# -----------------------------------------------------------------------------
# Tools
CC=$(ARM_GCC_PATH)gcc
OBJCOPY=$(ARM_GCC_PATH)objcopy
NM=$(ARM_GCC_PATH)nm
SIZE=$(ARM_GCC_PATH)size

# -----------------------------------------------------------------------------
# Boards definitions
BOARD_ID?=arduino_zero

# -----------------------------------------------------------------------------
# Compiler options
# eliminate PARANOIA define to save a tiny amount of code (~40B)
CFLAGS_EXTRA=-D$(SDCARD) -D__$(MCU)__ -DBOARD_ID_$(BOARD_ID) -DPARANOIA -DBOOT_$(BOOT)
CFLAGS=-mthumb -mcpu=cortex-m0plus -Wall -c -std=gnu99 -ffunction-sections -fdata-sections -nostdlib -nostartfiles --param max-inline-insns-single=500 -Wa,-adhlns=$(<:%.c=$(BUILD_DIR)/%.lst)
ifdef DEBUG
  CFLAGS+= -g3 -ggdb -Og -DDEBUG=1
else
  CFLAGS+= -g3  -Os -DDEBUG=0
endif

ELF=$(NAME).elf
BIN=$(NAME).bin
HEX=$(NAME).hex
SYM= $(NAME).sym

INCLUDES= -I"$(MODULE_PATH)/hardware/samd/$(REV_ARCH)" -I"$(MODULE_PATH)/tools/CMSIS-Atmel/$(REV_CMSIS)/CMSIS"
INCLUDES+= -I"$(MODULE_PATH)/tools/CMSIS-Atmel/$(REV_CMSIS)/CMSIS/Device/ATMEL" 
#-I"$(MODULE_PATH_ARDUINO)/tools/CMSIS/4.5.0/CMSIS/Include"  

INCLUDES+= -I"$(MODULE_PATH)/hardware/samd/$(REV_ARCH)/variants/Pilo"  -I"$(MODULE_PATH)/hardware/samd/$(REV_ARCH)"  -I"$(MODULE_PATH)/hardware/samd/$(REV_ARCH)/cores/arduino" -I"$(MODULE_PATH)/hardware/samd/$(REV_ARCH)\cores\ASF\thirdparty\CMSIS\Include"

#INCLUDES= -I"$(MODULE_PATH)/hardware/samd/1.6.19/" -I"$(MODULE_PATH)/tools/CMSIS-Atmel/CMSIS/Device/ATMEL/" 
#INCLUDES+= -I"$(MODULE_PATH)/hardware/samd/1.6.19/variants/Pilo"  -I"$(MODULE_PATH)/hardware/samd/1.6.19/cores/arduino" 
#INCLUDES+= -I"$(MODULE_PATH)/tools/CMSIS-Atmel/1.1.1-Zoubworld/CMSIS/Device/ATMEL/"  -I"$(MODULE_PATH_ARDUINO)/tools/CMSIS/4.5.0/CMSIS/Include/" 



# -----------------------------------------------------------------------------
# Linker options
LDFLAGS=-mthumb -mcpu=cortex-m0plus -Wall -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--unresolved-symbols=report-all
LDFLAGS+=-Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols --specs=nano.specs --specs=nosys.specs  
##debug
LDFLAGS+=-Wl,--cref -Wl,-Map,$(NAME).map

# -----------------------------------------------------------------------------
# Source files and objects
ifeq ($(findstring SAMC21,$(MCU)),SAMC21)
SOURCES= \
  board_driver_led.c \
  board_driver_serial.c \
  board_init.c \
  board_startup.c \
  util.c \
  main.c \
  sam_ba_monitor.c \
  sam_ba_serial.c
#  SDCard/sdBootloader.c \
#  SDCard/mmcbbp.c \
#  SDCard/pff.c \

else ifeq ($(findstring SAMD20,$(MCU)),SAMD20)
SOURCES= \
  board_driver_led.c \
  board_driver_serial.c \
  board_init.c \
  board_startup.c \
  util.c \
  main.c \
  sam_ba_monitor.c \
  sam_ba_serial.c
#  SDCard/sdBootloader.c \
#  SDCard/mmcbbp.c \
#  SDCard/pff.c \

else
SOURCES= \
  board_driver_led.c \
  board_driver_serial.c \
  board_driver_usb.c \
  board_init.c \
  board_startup.c \
  util.c \
  main.c \
  sam_ba_usb.c \
  sam_ba_cdc.c \
  sam_ba_monitor.c \
  sam_ba_serial.c
endif


OBJECTS=$(addprefix $(BUILD_DIR)/, $(SOURCES:.c=.o))
DEPS=$(addprefix $(BUILD_DIR)/, $(SOURCES:.c=.d))
ifneq "test$(AVRSTUDIO_EXE_PATH)" "test"
  AS_BUILD=copy_for_atmel_studio
  AS_CLEAN=clean_for_atmel_studio
else
  AS_BUILD=
  AS_CLEAN=
endif


lss: $(LSS)


sym: $(SYM) 
test:
	echo TERM=$(TERM)
	echo OS=$(OS)
	echo REV_ARCH=$(REV_ARCH)
	echo REV_CMSIS=$(REV_CMSIS)
	echo T=$(T)
	echo MODULE_PATH=$(MODULE_PATH)
	echo MODULE_PATH_ARDUINO=$(MODULE_PATH_ARDUINO)
	echo INCLUDES=$(INCLUDES)
	
all: print_info $(SOURCES) deps $(BIN) $(HEX) sym lss $(SYM) $(AS_BUILD) jlink mv
mv:
	cp -f $(BIN) ./binaries/

jlink:
	cat ../../variants/Pilo/jlink_scripts/bootloader.jlink  | sed "s/%%FILE%%/..\/..\/..\/bootloaders\/Pilo\/binaries\/sam_ba_Pilo_$(MCU).bin/" | sed "s/%%ADDR%%/0/" > ../../variants/Pilo/jlink_scripts/bootloader-$(MCU).jlink
deps: $(BUILD_DIR)  $(DEPS)
$(OBJECTS): Makefile
$(ELF): Makefile $(BUILD_DIR) $(OBJECTS)
	@echo ----------------------------------------------------------
	@echo Creating ELF binary
	"$(CC)" -L. -L$(BUILD_DIR) $(LDFLAGS) -Os -Wl,--gc-sections -save-temps -Tlinker_scripts/$(LINKER_SCRIPT) -Wl,-Map,"$(BUILD_DIR)/$(NAME).map" -o "$(BUILD_DIR)/$(ELF)" -Wl,--start-group $(OBJECTS) -lm -Wl,--end-group
	@"$(NM)" "$(BUILD_DIR)/$(ELF)" >"$(BUILD_DIR)/$(NAME)_symbols.txt"
	@"$(SIZE)" --format=sysv -t -x $(BUILD_DIR)/$(ELF)

$(BIN): $(ELF)
	@echo ----------------------------------------------------------
	@echo Creating flash binary $(BUILD_DIR)/$< $@
	@"$(OBJCOPY)" -O binary $(BUILD_DIR)/$< $@

$(HEX): $(ELF)
	@echo ----------------------------------------------------------
	@echo Creating flash binary
	"$(OBJCOPY)" -O ihex $(BUILD_DIR)/$< $@

$(BUILD_DIR)/%.o: %.c
	@echo ----------------------------------------------------------
	@echo Compiling $< to $@
	"$(CC)" $(CFLAGS) $(CFLAGS_EXTRA) $(INCLUDES) $< -o $@
	@echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Create symbol table from target output file.
$(SYM): $(ELF)
	@echo $(MSG_SYMBOL_TABLE)
	"$(NM)" -n $(BUILD_DIR)/$< > $@
	 
# Create extended listing from target output file.
$(LSS): $(ELF)
	@echo $(MSG_EXTENDED_LISTING)
	"$(OBJDUMP)" -h -S $(BUILD_DIR)/$< > $@
	
$(BUILD_DIR):
	@echo ----------------------------------------------------------
	@echo Creating build folder
	-mkdir $(BUILD_DIR)
	-mkdir $(BUILD_DIR)$(PATHSEP)SDCard
	-mkdir binaries

print_info:
	@echo ----------------------------------------------------------
	@echo Compiling bootloader using
	@echo BASE PATH = $(MODULE_PATH)
	@echo GCC  PATH = $(ARM_GCC_PATH)
	@echo OS        = $(OS)
	@echo CC        = $(CC)
	@echo TERM      = $(TERM)
	@echo SHELL     = $(SHELL)
	"$(CC)" -v
#	env

copy_for_atmel_studio: $(BIN) $(HEX)
	@echo ----------------------------------------------------------
	@echo Atmel Studio detected, copying ELF to project root for debug
	cp $(BUILD_DIR)$(PATHSEP)$(ELF) .

clean_for_atmel_studio:
	@echo ----------------------------------------------------------
	@echo Atmel Studio detected, cleaning ELF from project root
	-$(RM) .$(PATHSEP)$(ELF)

clean: $(AS_CLEAN) mostly_clean
	@echo ----------------------------------------------------------
	@echo Cleaning project
	-$(RM) $(BIN)
	-$(RM) $(HEX)
	-$(RM) $(BUILD_DIR)$(PATHSEP)SDCard$(PATHSEP)*.*
	-$(RM) $(BUILD_DIR)$(PATHSEP)*.*
	-rmdir $(BUILD_DIR)$(PATHSEP)SDCard
	-rmdir $(BUILD_DIR)
	-mkdir $(BUILD_DIR)
	

mostly_clean: $(AS_CLEAN)
	@echo ----------------------------------------------------------
	@echo Cleaning project except bin
	-$(RM) $(OBJECTS)
	-$(RM) $(DEPS)
	-$(RM) *.o
	-$(RM) *.d	
	-$(RM) $(DEPS)  $(LSS)  $(SYM)

.phony: print_info $(BUILD_DIR)
%.lss: %.elf
	@echo
	@echo $(MSG_EXTENDED_LISTING) $@
	$(OBJDUMP) -h -S -z $< > $@
# Preprocess: create dependancy files from C/S source files.
$(BUILD_DIR)/%.d: %.c 
	@echo ----------------------------------------------------------
	@echo COMPILING_DEPENDENCY $< to $@
	"$(CC)" -M $(CFLAGS) $(CFLAGS_EXTRA) $(INCLUDES)  -MD -MP -MT '$*.i $*.si $*.o' -MF $@ $<




