#!/bin/bash
# Flash SoftDevice S132 6.1.1 only (no application).
set -euo pipefail

SDK_ROOT="${SDK_ROOT:-$HOME/.nRF5_SDK/nRF5_SDK_15.3.0_59ac345}"
SD_HEX="${SDK_ROOT}/components/softdevice/s132/hex/s132_nrf52_6.1.1_softdevice.hex"

if [[ ! -f "$SD_HEX" ]]; then
  echo "Missing SoftDevice hex: $SD_HEX"
  echo "Set SDK_ROOT or install nRF5 SDK 15.3.0"
  exit 1
fi

nrfjprog -f nrf52 --eraseall
nrfjprog -f nrf52 --program "$SD_HEX" --verify
nrfjprog -f nrf52 --reset
echo "SoftDevice S132 6.1.1 programmed."
