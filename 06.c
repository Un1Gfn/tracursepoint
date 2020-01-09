// 06.c

#include <ncurses.h>

int main(){

  initscr();
  noecho();
  cbreak();

  int yMax=0,xMax=0;

  getmaxyx(stdscr,yMax,xMax);

  WINDOW *inputwin=newwin(3,xMax-12,yMax-5,5);
  box(inputwin,0,0);
  refresh();
  wrefresh(inputwin);

  // int c=wgetch(inputwin);
  // if(c=='j'){
  //   // (1,1) avoid border
  //   mvwprintw(inputwin,1,1,"You pressed j!");
  //   wrefresh(inputwin);
  // }

  keypad(inputwin,true);

  int c=wgetch(inputwin);
  // if(c==KEY_F(123)){
  if(c==KEY_UP){
    mvwprintw(inputwin,1,1,"You pressed key up!");
    wrefresh(inputwin);
  }

  getch();
  endwin();

  return 0;
}

