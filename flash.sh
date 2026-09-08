#!/bin/bash
# Flash GH3026 probe firmware (no SoftDevice, app starts at 0x00000).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")" && pwd)"
HEX="${ROOT}/pca10040/blank/armgcc/_build/nrf52832_xxaa.hex"

if [[ ! -f "$HEX" ]]; then
  echo "Missing $HEX — run: make"
  exit 1
fi

nrfjprog -f nrf52 --eraseall
nrfjprog -f nrf52 --program "$HEX" --verify
nrfjprog -f nrf52 --reset
echo "Done."
