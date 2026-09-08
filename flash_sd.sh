#!/bin/bash
# Original holyuart-style flash: SoftDevice S132 6.1.1 + application.
# App must be linked for SoftDevice (start ~0x26000), NOT the current blank probe at 0x00000.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
SDK_ROOT="${SDK_ROOT:-$HOME/.nRF5_SDK/nRF5_SDK_15.3.0_59ac345}"
SD_HEX="${SDK_ROOT}/components/softdevice/s132/hex/s132_nrf52_6.1.1_softdevice.hex"
APP_HEX="${1:-$ROOT/pca10040/blank/armgcc/_build/nrf52832_xxaa.hex}"

if [[ ! -f "$SD_HEX" ]]; then
  echo "Missing SoftDevice hex: $SD_HEX"
  exit 1
fi
if [[ ! -f "$APP_HEX" ]]; then
  echo "Missing app hex: $APP_HEX"
  echo "Usage: $0 [path/to/app.hex]"
  exit 1
fi

echo "SoftDevice: $SD_HEX"
echo "App:        $APP_HEX"
nrfjprog -f nrf52 --eraseall
nrfjprog -f nrf52 --program "$SD_HEX" --verify
nrfjprog -f nrf52 --program "$APP_HEX" --verify
nrfjprog -f nrf52 --reset
echo "Done (SoftDevice + App)."
