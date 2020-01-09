// slider.c

#include <ncurses.h>
#include "slider.h"
#include "errors.h"

bool validval(int val){
  return 0<=val && val<=RANGE ;
}

bool validpos(int pos){
  return 2<=pos && pos<=RANGE+2 ;
}

int to_pos(int val){
  if(!validval(val))
    ERR2;
  return val+2;
}

int to_val(int pos){
  if(!validpos(pos))
    ERR2;
  return pos-2;
}

void place_handle(WINDOW *slider,int pos_new){
  if(!validpos(pos_new))
    ERR2;
  wattron(slider,A_REVERSE);
  mvwaddch(slider,2,pos_new,SLHANDLE);
  wattroff(slider,A_REVERSE);
}

void slider_init(WINDOW *slider,int pos_initial){
  if(!validpos(pos_initial))
    ERR2;
  box(slider,0,0);
  wmove(slider,2,2);
  for(int i=0;i<=RANGE;++i)
    waddch(slider,SLGROOVE);
  place_handle(slider,pos_initial);
  refresh();
  wrefresh(slider);
}

void slider_update(WINDOW *slider,int pos_new){
  if(!validpos(pos_new))
    ERR2;
  int y=0,x=0;
  getyx(slider,y,x);
  // Erase previous handle
  mvwaddch(slider,2,x-1,SLGROOVE);
  // Place new handle
  place_handle(slider,pos_new+1);
  wrefresh(slider);
}
