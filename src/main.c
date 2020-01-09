// main.c

// clear; gcc -std=c11 -g -O0 -Wall -Wextra -Winline $(pkg-config --libs ncurses) main.c utility.c slider.c

#include <ncurses.h>
#include "utility.h"
#include "slider.h"
#include "errors.h"

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
  slider_init(win_sensitivity,to_pos(get_sensitivity()));
  slider_init(win_speed,to_pos(get_speed()));

  // getch();
  // slider_update(win_sensitivity,valto_pos(27));
  // slider_update(win_speed,valto_pos(54));

  while(1){
    int ch=getch();
    // printw("%X\n",ch);
    if(ch=='x')
      break;
    if(ch==KEY_MOUSE){
      MEVENT event={};
      if(getmouse(&event)!=OK)
        ERR2;
      // printw("%d (%d, %d, %d) %X\n",
      //   event.id,
      //   event.y,
      //   event.x,
      //   event.z,
      //   event.bstate
      // );
      if(wenclose(win_sensitivity,event.y,event.x)){
        printw("O ");
      }
      if(wenclose(win_speed,event.y,event.x)){
        attron(A_REVERSE);
        printw("O ");
        attroff(A_REVERSE);
      }
    }
  }



  // getch();
  delwin(win_sensitivity);
  delwin(win_speed);
  win_sensitivity=NULL;
  win_speed=NULL;

  endwin();

  return 0;
}

