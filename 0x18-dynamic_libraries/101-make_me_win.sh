#!/bin/bash
gcc -shared -o /tmp/librand.so rand.c
LD_PRELOAD=/tmp/librand.so
