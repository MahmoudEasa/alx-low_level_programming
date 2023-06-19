#!/bin/bash
wget -P /tmp/ https://raw.github.com/MahmoudEasa/alx-low_level_programming/master/0x18-dynamic_libraries/librand.so
LD_PRELOAD=/tmp/librand.so
