// slider.c

#include <ncurses.h>
#include "slider.h"

void handle_place(WINDOW *slider,int pos){
  wattron(slider,A_REVERSE);
  mvwaddch(slider,2,pos,SLHANDLE);
  wattroff(slider,A_REVERSE);
}

void slider_init(WINDOW *slider,int initial){
  box(slider,0,0);
  wmove(slider,2,2);
  for(int i=0;i!=RANGE+1;++i)
    waddch(slider,SLGROOVE);
  handle_place(slider,initial+1);
  // int y=0,x=0;
  // getyx(slider,y,x);
  // printw("(%d, %d)\n",y,x);
  refresh();
  wrefresh(slider);
}


void slider_update(WINDOW *slider,int new){
  int y=0,x=0;
  getyx(slider,y,x);
  // Erase previous handle
  mvwaddch(slider,2,x-1,SLGROOVE);
  // Place new handle
  handle_place(slider,new+1);
  wrefresh(slider);
}