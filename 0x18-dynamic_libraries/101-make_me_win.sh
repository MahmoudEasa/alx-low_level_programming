#!/bin/bash
gcc -shared -o /tmp/librand.so ./rand.c
export LD_PRELOAD=/tmp/librand.so
