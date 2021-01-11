#!/bin/bash

clear

cat <<EOF
xinput set-prop 'TPPS/2 IBM TrackPoint' 'libinput Accel Speed' -0.2
EOF

read -r

gcc \
  -std=c11 \
  -g -O0 -Wall -Wextra -Winline -fdiagnostics-color=always \
  $(pkg-config --libs ncurses) \
  main.c utility.c slider.c \
  |& less -SRM +%
