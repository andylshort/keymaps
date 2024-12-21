#!/bin/bash
set -e
if [ ! -d "$QMK_FIRMWARE_DIR" ]; then
    echo "QMK_FIRMWARE_DIR environment variable not set."
    echo "Please set this and try again."
    exit 1
fi
CWD=$(pwd)
ln -sfvn $CWD/preonic $QMK_FIRMWARE_DIR/keyboards/preonic/keymaps/andylshort
ln -sfvn $CWD/ferris  $QMK_FIRMWARE_DIR/keyboards/ferris/keymaps/andylshort

