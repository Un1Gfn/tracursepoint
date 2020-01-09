// main.c

// clear; gcc -std=c11 -g -O0 -Wall -Wextra -Winline $(pkg-config --libs ncurses) main.c utility.c slider.c

#include <ncurses.h>
#include <error.h>
#include "utility.h"
#include "slider.h"

// const int sensitivity=55;

int main(){

  initscr();
  cbreak();
  noecho();
  curs_set(0);
  keypad(stdscr,1);

  int yM0=0;
  int xM0=0;
  getmaxyx(stdscr,yM0,xM0);
  const int xM=xM0;
  const int yM=yM0;

  WINDOW *win_sensitivity=newwin(5,RANGE+5,(yM-5)/2,(xM-RANGE-5)/2);
  slider_init(win_sensitivity,get_sensitivity());

  getch();
  slider_update(win_sensitivity,27);

  getch();
  endwin();

  return 0;
}

