PROJECT_NAME     := gh3026_pca10040
TARGETS          := nrf52832_xxaa
OUTPUT_DIRECTORY := _build

# Override with: make SDK_ROOT=/path/to/nRF5_SDK_15.3.0_59ac345
SDK_ROOT ?= $(HOME)/.nRF5_SDK/nRF5_SDK_15.3.0_59ac345
GNU_INSTALL_ROOT ?= /opt/homebrew/bin/
GNU_PREFIX ?= arm-none-eabi
PROJ_DIR := ../../..

$(OUTPUT_DIRECTORY)/nrf52832_xxaa.out: \
  LINKER_SCRIPT  := gh3026_gcc_nrf52.ld

# Source files common to all targets
SRC_FILES += \
  $(SDK_ROOT)/modules/nrfx/mdk/gcc_startup_nrf52.S \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_rtt.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_serial.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_default_backends.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_frontend.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_str_formatter.c \
  $(SDK_ROOT)/components/boards/boards.c \
  $(SDK_ROOT)/components/libraries/util/app_error.c \
  $(SDK_ROOT)/components/libraries/util/app_error_handler_gcc.c \
  $(SDK_ROOT)/components/libraries/util/app_error_weak.c \
  $(SDK_ROOT)/components/libraries/util/app_util_platform.c \
  $(SDK_ROOT)/components/libraries/util/nrf_assert.c \
  $(SDK_ROOT)/components/libraries/atomic_fifo/nrf_atfifo.c \
  $(SDK_ROOT)/components/libraries/atomic/nrf_atomic.c \
  $(SDK_ROOT)/components/libraries/balloc/nrf_balloc.c \
  $(SDK_ROOT)/external/fprintf/nrf_fprintf.c \
  $(SDK_ROOT)/external/fprintf/nrf_fprintf_format.c \
  $(SDK_ROOT)/components/libraries/memobj/nrf_memobj.c \
  $(SDK_ROOT)/components/libraries/ringbuf/nrf_ringbuf.c \
  $(SDK_ROOT)/components/libraries/strerror/nrf_strerror.c \
  $(SDK_ROOT)/modules/nrfx/soc/nrfx_atomic.c \
  $(PROJ_DIR)/main.c \
  $(PROJ_DIR)/i2c.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT_printf.c \
  $(SDK_ROOT)/modules/nrfx/mdk/system_nrf52.c \

# Include folders common to all targets
INC_FOLDERS += \
  $(SDK_ROOT)/components \
  $(SDK_ROOT)/modules/nrfx/mdk \
  $(PROJ_DIR) \
  $(SDK_ROOT)/components/libraries/strerror \
  $(SDK_ROOT)/components/toolchain/cmsis/include \
  $(SDK_ROOT)/components/libraries/util \
  ../config \
  $(SDK_ROOT)/components/libraries/balloc \
  $(SDK_ROOT)/components/libraries/ringbuf \
  $(SDK_ROOT)/modules/nrfx/hal \
  $(SDK_ROOT)/components/libraries/log \
  $(SDK_ROOT)/modules/nrfx \
  $(SDK_ROOT)/components/libraries/experimental_section_vars \
  $(SDK_ROOT)/components/libraries/delay \
  $(SDK_ROOT)/integration/nrfx \
  $(SDK_ROOT)/components/drivers_nrf/nrf_soc_nosd \
  $(SDK_ROOT)/components/libraries/atomic \
  $(SDK_ROOT)/components/libraries/atomic_fifo \
  $(SDK_ROOT)/components/boards \
  $(SDK_ROOT)/components/libraries/memobj \
  $(SDK_ROOT)/external/fprintf \
  $(SDK_ROOT)/external/segger_rtt \
  $(SDK_ROOT)/components/libraries/log/src \

# Libraries common to all targets
LIB_FILES += \

# Optimization flags
OPT = -O3 -g3

# C flags common to all targets
CFLAGS += $(OPT)
CFLAGS += -DBOARD_PCA10040
CFLAGS += -DBSP_DEFINES_ONLY
CFLAGS += -DCONFIG_GPIO_AS_PINRESET
CFLAGS += -DFLOAT_ABI_HARD
CFLAGS += -DNRF52
CFLAGS += -DNRF52832_XXAA
CFLAGS += -DNRF52_PAN_74
CFLAGS += -mcpu=cortex-m4
CFLAGS += -mthumb -mabi=aapcs
CFLAGS += -Wall
# GCC 15+ is stricter than the original Nordic SDK toolchain; keep warnings non-fatal.
# CFLAGS += -Werror
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fno-builtin -fshort-enums
CFLAGS += -Wno-unused-function
CFLAGS += -Wno-unused-variable

# C++ flags common to all targets
CXXFLAGS += $(OPT)

# Assembler flags common to all targets
ASMFLAGS += -g3
ASMFLAGS += -mcpu=cortex-m4
ASMFLAGS += -mthumb -mabi=aapcs
ASMFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
ASMFLAGS += -DBOARD_PCA10040
ASMFLAGS += -DBSP_DEFINES_ONLY
ASMFLAGS += -DCONFIG_GPIO_AS_PINRESET
ASMFLAGS += -DFLOAT_ABI_HARD
ASMFLAGS += -DNRF52
ASMFLAGS += -DNRF52832_XXAA
ASMFLAGS += -DNRF52_PAN_74

# Linker flags
LDFLAGS += $(OPT)
LDFLAGS += -mthumb -mabi=aapcs -L$(SDK_ROOT)/modules/nrfx/mdk -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
LDFLAGS += -Wl,--gc-sections
LDFLAGS += --specs=nano.specs

nrf52832_xxaa: CFLAGS += -D__HEAP_SIZE=8192
nrf52832_xxaa: CFLAGS += -D__STACK_SIZE=8192
nrf52832_xxaa: ASMFLAGS += -D__HEAP_SIZE=8192
nrf52832_xxaa: ASMFLAGS += -D__STACK_SIZE=8192

LIB_FILES += -lc -lnosys -lm


.PHONY: default help

default: check_sdk nrf52832_xxaa

help:
	@echo following targets are available:
	@echo		nrf52832_xxaa
	@echo		flash      - flash application hex
	@echo		erase      - erase chip
	@echo		SDK_ROOT=$(SDK_ROOT)

check_sdk:
	@test -f "$(SDK_ROOT)/components/toolchain/gcc/Makefile.common" || ( \
		echo "ERROR: nRF5 SDK not found at: $(SDK_ROOT)"; \
		echo "Install nRF5 SDK 15.3.0 and/or pass SDK_ROOT=/path/to/nRF5_SDK_15.3.0_59ac345"; \
		exit 1)

TEMPLATE_PATH := $(SDK_ROOT)/components/toolchain/gcc

include $(TEMPLATE_PATH)/Makefile.common

$(foreach target, $(TARGETS), $(call define_target, $(target)))

.PHONY: flash flash_sd erase check_sdk

# Current firmware is linked at 0x00000 (no SoftDevice).
flash: default
	@echo "Flashing $(OUTPUT_DIRECTORY)/nrf52832_xxaa.hex (ERASE_ALL, no SoftDevice)"
	nrfjprog -f nrf52 --eraseall
	nrfjprog -f nrf52 --program $(OUTPUT_DIRECTORY)/nrf52832_xxaa.hex --verify
	nrfjprog -f nrf52 --reset

# Original holyuart style (only valid for SoftDevice-linked apps)
flash_sd: default
	@echo "Flashing SoftDevice 6.1.1 + app"
	nrfjprog -f nrf52 --eraseall
	nrfjprog -f nrf52 --program $(SDK_ROOT)/components/softdevice/s132/hex/s132_nrf52_6.1.1_softdevice.hex --verify
	nrfjprog -f nrf52 --program $(OUTPUT_DIRECTORY)/nrf52832_xxaa.hex --verify
	nrfjprog -f nrf52 --reset

erase:
	nrfjprog -f nrf52 --eraseall
