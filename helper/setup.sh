#!/bin/bash

echo "[+] We need sudo authorization to install packages."
sudo
apt update
apt install -y gpiod
wget https://github.com/joan2937/pigpio/archive/master.zip
unzip master.zip
cd pigpio-master
make
sudo make install
echo "[+] All packages installed successfully."
