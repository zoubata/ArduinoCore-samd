#!/bin/bash -ex
BOARD_ID=Pilo MCU=SAMC21J18A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Pilo MCU=SAMC21J17A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Pilo MCU=SAMC21J16A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Pilo MCU=SAMC21J15A SDCARD=SDCARD_DISABLED make all mostly_clean

BOARD_ID=Generic_x21E MCU=SAMC21J18A SDCARD=SDCARD_DISABLED make all mostly_clean

BOARD_ID=arduino_zero NAME=samd21_sam_ba make clean all


BOARD_ID=genuino_zero NAME=samd21_sam_ba_genuino make clean all

BOARD_ID=arduino_mkr1000 NAME=samd21_sam_ba_arduino_mkr1000 make clean all
mv -v samd21_sam_ba_arduino_mkr1000.* ../mkr1000/

BOARD_ID=genuino_mkr1000 NAME=samd21_sam_ba_genuino_mkr1000 make clean all
mv -v samd21_sam_ba_genuino_mkr1000.* ../mkr1000/

BOARD_ID=arduino_mkrzero NAME=samd21_sam_ba_arduino_mkrzero make clean all
mv -v samd21_sam_ba_arduino_mkrzero.* ../mkrzero/

BOARD_ID=arduino_mkrfox1200 NAME=samd21_sam_ba_arduino_mkrfox1200 make clean all
mv -v samd21_sam_ba_arduino_mkrfox1200.* ../mkrfox1200/
BOARD_ID=Generic_x21E MCU=SAMD21E15A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21E MCU=SAMD21E16A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21E MCU=SAMD21E17A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21E MCU=SAMD21E18A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21E MCU=SAML21E15B SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21E MCU=SAML21E16B SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21E MCU=SAML21E17B SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21E MCU=SAML21E18B SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21E MCU=SAMC21E15A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21E MCU=SAMC21E16A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21E MCU=SAMC21E17A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21E MCU=SAMC21E18A SDCARD=SDCARD_DISABLED make all mostly_clean

BOARD_ID=Generic_x21G MCU=SAMD21G15A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21G MCU=SAMD21G16A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21G MCU=SAMD21G17A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21G MCU=SAMD21G18A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21G MCU=SAML21G16B SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21G MCU=SAML21G17B SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21G MCU=SAML21G18B SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21G MCU=SAMC21G15A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21G MCU=SAMC21G16A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21G MCU=SAMC21G17A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21G MCU=SAMC21G18A SDCARD=SDCARD_DISABLED make all mostly_clean

BOARD_ID=Generic_x21J MCU=SAMD21J15A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21J MCU=SAMD21J16A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21J MCU=SAMD21J17A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21J MCU=SAMD21J18A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21J MCU=SAML21J16B SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21J MCU=SAML21J17B SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21J MCU=SAML21J18B SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21J MCU=SAMC21J15A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21J MCU=SAMC21J16A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21J MCU=SAMC21J17A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Generic_x21J MCU=SAMC21J18A SDCARD=SDCARD_DISABLED make all mostly_clean
mv -v *.bin ./binaries/

echo Done building bootloaders!

