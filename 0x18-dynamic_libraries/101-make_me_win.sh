#!/bin/bash

export LD_PRELOAD=./libwinning.so
./gm 9 8 10 24 75 9
