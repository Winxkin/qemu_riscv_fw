#!/bin/bash

PRJ_PATH="$(pwd)/../qemu_riscv64/"

echo "project source $path_to_prj"

source $HOME/zephyrproject/.venv/bin/activate
cd $HOME/zephyrproject/zephyr

echo "Now in $(pwd)"

west build -p always -b qemu_riscv64 $PRJ_PATH
