#!/bin/bash

echo "[+] System Kernel Information"
sudo uname -a
echo "*"

echo "[+] Distribution Information"
sudo lsb_release -a
echo "*"

echo "[+] System Name"
sudo hostname
echo "*"

echo "[+] Memory Usage"
sudo free -h
echo "*"

echo "[+] Disk Usage"
sudo df -h
echo "*"

echo "[+] System Uptime and Load Information"
uptime
