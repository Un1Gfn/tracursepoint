// 03.c

#include <ncurses.h>

int main(){

  initscr();
  cbreak();
  // raw();
  noecho();

  int height=10;
  int width=20;
  int start_y=10;
  int start_x=10;

  WINDOW *win=newwin(height,width,start_y,start_x);
  refresh();

  // border
  // box(win,(int)'g',(int)'h');
  int left=(int)'g';
  int right=(int)'g';
  int top=(int)'h';
  int bottom=(int)' ';
  int tlc=(int)'+';
  int trc=(int)'+';
  int blc=(int)' ';
  int brc=(int)' ';

  wborder(win,left,right,top,bottom,tlc,trc,blc,brc);

  mvwprintw(win,1,1,"this is my box");
  wrefresh(win);

  getch();
  getch();

  endwin();

  return 0;
}