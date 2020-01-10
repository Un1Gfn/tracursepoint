// slider.c

#include <ncurses.h>
#include "slider.h"
#include "errors.h"

bool validval(int val){
  return 0<=val && val<=RANGE ;
}

bool validxpos(int xpos){
  return 2<=xpos && xpos<=RANGE+2 ;
}

int to_xpos(int val){
  if(!validval(val))
    ERR2;
  return val+2;
}

int to_val(int pos){
  if(!validxpos(pos))
    ERR2;
  return pos-2;
}

void place_handle(WINDOW *slider,int pos_new){
  if(!validxpos(pos_new))
    ERR2;
  wattron(slider,A_REVERSE);
  mvwaddch(slider,2,pos_new,SLHANDLE);
  wattroff(slider,A_REVERSE);
}

void slider_init(WINDOW *slider,int pos_initial/*,char legend*/){
  if(!validxpos(pos_initial))
    ERR2;
  box(slider,0,0);

  // Add legend to the left of the slider
  // int ybeg=0;
  // int xend=0;
  // getbegyx(slider,ybeg,xend);
  // for(int y=ybeg;y!=ybeg+HEIGHT;++y){
  //   for(int x=xend;x!=xend-HEIGHT;--x)
  //     mvaddch(y,x,legend);
  // }
  // refresh();

  wmove(slider,2,2);
  for(int i=0;i<=RANGE;++i)
    waddch(slider,SLGROOVE);
  place_handle(slider,pos_initial);
  refresh();
  wrefresh(slider);
}

void slider_update(WINDOW *slider,int pos_new){
  if(!validxpos(pos_new))
    ERR2;
  int y=0,x=0;
  getyx(slider,y,x);
  // Erase previous handle
  mvwaddch(slider,2,x-1,SLGROOVE);
  // Place new handle
  place_handle(slider,pos_new);
  wrefresh(slider);
}
