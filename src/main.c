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
  mousemask(BUTTON1_PRESSED,NULL);

  int yM0=0;
  int xM0=0;
  getmaxyx(stdscr,yM0,xM0);
  const int xM=xM0;
  const int yM=yM0;

  // WINDOW *win_sensitivity=newwin(5,RANGE+1+2+2,(yM-5)/2,(xM-RANGE-5)/2);
  WINDOW *win_sensitivity=newwin(HEIGHT,WIDTH,  (yM-2*HEIGHT)/3       ,(xM-WIDTH)/2);
  WINDOW *win_speed      =newwin(HEIGHT,WIDTH,2*(yM-2*HEIGHT)/3+HEIGHT,(xM-WIDTH)/2);
  slider_init(win_sensitivity,get_sensitivity());
  slider_init(win_speed,get_speed());

  getch();
  slider_update(win_sensitivity,27);
  slider_update(win_speed,54);

  getch();
  delwin(win_sensitivity);
  delwin(win_speed);
  win_sensitivity=NULL;
  win_speed=NULL;

  endwin();

  return 0;
}

