#!/bin/bash

cd $HOME
echo "Now in $(pwd)"

if [ -e "$HOME/zephyr-sdk-0.17.0_linux-x86_64.tar.xz" ]; then
    echo "zephyr-sdk-0.17.0_linux-x86_64.tar.xz exist."
else
    echo "download sdk zephyr-sdk-0.17.0_linux-x86_64.tar.xz."
    wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.17.0/zephyr-sdk-0.17.0_linux-x86_64.tar.xz
    wget -O - https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.17.0/sha256.sum | shasum --check --ignore-missing
fi

if [ -e "$HOME/zephyr-sdk-0.17.0" ]; then
    echo "zephyr-sdk-0.17.0 exist."
else
    tar xvf zephyr-sdk-0.17.0_linux-x86_64.tar.xz
    cd zephyr-sdk-0.17.0
    ./setup.sh
fi


cd $HOME

if [ -e "$HOME/zephyrproject/.venv" ]; then
    echo "$HOME/zephyrproject/.venv exist."
else
    python3 -m venv $HOME/zephyrproject/.venv
fi

source $HOME/zephyrproject/.venv/bin/activate
pip install west
west init $HOME/zephyrproject
cd $HOME/zephyrproject
west update
west zephyr-export

pip install -r $HOME/zephyrproject/zephyr/scripts/requirements.txt

cd $HOME/zephyrproject/zephyr
west sdk install
