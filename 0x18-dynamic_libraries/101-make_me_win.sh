#!/bin/bash
gcc -shared -o /tmp/librand.so ./rand.c
LD_PRELOAD=/tmp/librand.so ./gm 9 8 10 24 75 9
