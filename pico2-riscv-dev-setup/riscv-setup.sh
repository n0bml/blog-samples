#!/usr/bin/env bash
set -e

PICO_PATH="${HOME}/pico"
TOOLCHAIN_PATH="${PICO_PATH}/toolchains"

git clone https://github.com/riscv/riscv-gnu-toolchain
cd riscv-gnu-toolchain

git clone https://github.com/gcc-mirror/gcc gcc-14 -b releases/gcc-14

./configure --prefix="${TOOLCHAIN_PATH}/gcc14-rp2350-no-zcmp" --with-arch=rv32ima_zicsr_zifencei_zba_zbb_zbs_zbkb_zca_zcb --with-abi=ilp32 --with-multilib-generator="rv32ima_zicsr_zifencei_zba_zbb_zbs_zbkb_zca_zcb-ilp32--;rv32imac_zicsr_zifencei_zba_zbb_zbs_zbkb-ilp32--" --with-gcc-src="$(pwd)/gcc-14"

mkdir -p "${TOOLCHAIN_PATH}/gcc14-rp2350-no-zcmp"
time make -j "$(nproc)"
