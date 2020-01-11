#!/bin/bash

clear

gcc \
  -std=c11 \
  -g -O0 -Wall -Wextra -Winline -fdiagnostics-color=always \
  $(pkg-config --libs ncurses) \
  main.c utility.c slider.c \
  |& less -SRM +%
