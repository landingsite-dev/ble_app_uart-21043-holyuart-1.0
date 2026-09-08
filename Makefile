# GH3026 / nRF52832 top-level build
#
# Prerequisites:
#   - arm-none-eabi-gcc (e.g. brew install --cask gcc-arm-embedded)
#   - nRF5 SDK 15.3.0 at $(HOME)/.nRF5_SDK/nRF5_SDK_15.3.0_59ac345
#     or override: make SDK_ROOT=/path/to/sdk
#   - optional flash: nrfjprog / nrfutil

SDK_ROOT ?= $(HOME)/.nRF5_SDK/nRF5_SDK_15.3.0_59ac345
GNU_INSTALL_ROOT ?= /opt/homebrew/bin/
BUILD_DIR := pca10040/blank/armgcc

.PHONY: all clean flash flash_sd flash_softdevice erase help

all:
	$(MAKE) -C $(BUILD_DIR) SDK_ROOT="$(SDK_ROOT)" GNU_INSTALL_ROOT="$(GNU_INSTALL_ROOT)"

clean:
	$(MAKE) -C $(BUILD_DIR) SDK_ROOT="$(SDK_ROOT)" GNU_INSTALL_ROOT="$(GNU_INSTALL_ROOT)" clean

flash:
	$(MAKE) -C $(BUILD_DIR) SDK_ROOT="$(SDK_ROOT)" GNU_INSTALL_ROOT="$(GNU_INSTALL_ROOT)" flash

flash_sd:
	$(MAKE) -C $(BUILD_DIR) SDK_ROOT="$(SDK_ROOT)" GNU_INSTALL_ROOT="$(GNU_INSTALL_ROOT)" flash_sd

flash_softdevice:
	./flash_softdevice.sh

erase:
	$(MAKE) -C $(BUILD_DIR) SDK_ROOT="$(SDK_ROOT)" GNU_INSTALL_ROOT="$(GNU_INSTALL_ROOT)" erase

help:
	@echo "make                 - build GH3026 test firmware"
	@echo "make clean           - remove build outputs"
	@echo "make flash           - erase + flash app only (current probe, no SoftDevice)"
	@echo "make flash_softdevice - erase + flash SoftDevice S132 6.1.1 only"
	@echo "make flash_sd        - erase + SoftDevice 6.1.1 + app (SoftDevice-linked app)"
	@echo "make erase           - erase nRF52 chip"
	@echo "SDK_ROOT=$(SDK_ROOT)"
