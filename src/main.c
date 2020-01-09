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
  // mousemask(0,NULL);
  // mousemask(BUTTON1_CLICKED,NULL);
  mousemask(BUTTON1_PRESSED,NULL);

  int yM0=0;
  int xM0=0;
  getmaxyx(stdscr,yM0,xM0);
  const int xM=xM0;
  const int yM=yM0;

  WINDOW *win_sensitivity=newwin(HEIGHT,WIDTH,  (yM-2*HEIGHT)/3       ,(xM-WIDTH)/2);
  WINDOW *win_speed      =newwin(HEIGHT,WIDTH,2*(yM-2*HEIGHT)/3+HEIGHT,(xM-WIDTH)/2);

  // slider_init(win_sensitivity,to_xpos(27));
  // slider_init(win_speed,to_xpos(54));
  slider_init(win_sensitivity,to_xpos(get_sensitivity()));
  slider_init(win_speed,to_xpos(get_speed()));

  // getch();
  // slider_update(win_sensitivity,to_xpos(27));
  // slider_update(win_speed,to_xpos(54));

  while(1){
    int ch=getch();
    // printw("%X\n",ch);
    if(ch=='x')
      break;
    // if(ch==KEY_F5){
    //   printw("F5 ");
    //   // slider_update(win_sensitivity,to_xpos(get_sensitivity()));
    //   // slider_update(win_speed,to_xpos(get_speed()));
    // }
    if(ch=='r'){ // Reset to defaults
      set_sensitivity(DEFAULT_SENSITIVITY);
      set_speed(DEFAULT_SPEED);
      slider_update(win_sensitivity,to_xpos(DEFAULT_SENSITIVITY));
      slider_update(win_speed,to_xpos(DEFAULT_SPEED));
      continue;
    }
    if(ch==KEY_MOUSE){
      MEVENT event={};
      if(getmouse(&event)!=OK)
        ERR2;
      if(wenclose(win_sensitivity,event.y,event.x)){
        // printw("%d ",event.x);
        if(!wmouse_trafo(win_sensitivity,&event.y,&event.x,FALSE))
          ERR2;
        // printw("%d ",event.x);
        if(validxpos(event.x))
          slider_update(win_sensitivity,event.x);
        continue;
      }
      if(wenclose(win_speed,event.y,event.x)){
        // printw("%d ",event.x);
        if(!wmouse_trafo(win_speed,&event.y,&event.x,FALSE))
          ERR2;
        // printw("%d ",event.x);
        if(validxpos(event.x))
          slider_update(win_speed,event.x);
        continue;
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

