#!/bin/bash -ex
BOARD_ID=Pilo MCU=SAMC21J18A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Pilo MCU=SAMC21J17A SDCARD=SDCARD_DISABLED make all mostly_clean
BOARD_ID=Pilo MCU=SAMC21J16A SDCARD=SDCARD_DISABLED make all mostly_clean


mv -v *.bin ./binaries/

echo Done building bootloaders!

