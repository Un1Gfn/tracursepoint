// x_test.c

// gcc -std=c11 -g -O0 -Wall -Wextra -Winline -fdiagnostics-color=always $(pkg-config --libs xi x11 ncurses) accel.c accel_test.c

#include <stdio.h>
#include "accel.h"

int main(){

  open_accel();

  printf("%f\n",get_accel());

  close_accel();

  return 0;

}

