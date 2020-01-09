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
  mousemask(BUTTON1_PRESSED,NULL);

  int yM0=0;
  int xM0=0;
  getmaxyx(stdscr,yM0,xM0);
  const int xM=xM0;
  const int yM=yM0;

  WINDOW *win_sensitivity=newwin(HEIGHT,WIDTH,  (yM-2*HEIGHT)/3       ,(xM-WIDTH)/2);
  WINDOW *win_speed      =newwin(HEIGHT,WIDTH,2*(yM-2*HEIGHT)/3+HEIGHT,(xM-WIDTH)/2);

  // slider_init(win_sensitivity,to_pos(get_sensitivity()));
  // slider_init(win_speed,to_pos(get_speed()));

  slider_init(win_sensitivity,to_pos(27));
  slider_init(win_speed,to_pos(54));

  // getch();
  // slider_update(win_sensitivity,to_pos(27));
  // slider_update(win_speed,to_pos(54));

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
        // printw("O ");
        int yRel=event.y;
        int xRel=event.x;
        if(!wmouse_trafo(win_sensitivity,&yRel,&xRel,FALSE))
          ERR2;
        if(validxpos(xRel))
          printw("O ");
        else
          printw("X ");
        continue;
      }
      printw("- ");
      // if(wenclose(win_speed,event.y,event.x)){
      //   attron(A_REVERSE);
      //   printw("O ");
      //   attroff(A_REVERSE);
      //   // mouse_trafo
      // }
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

