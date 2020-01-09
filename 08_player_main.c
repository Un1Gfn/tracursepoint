// Player movement

// gcc -g -O0 -Wall -Winline $(pkg-config --libs ncurses) player_main.c player.c

#include <ncurses.h>
#include "player.h"

int main(){

  initscr();
  noecho();
  cbreak();
  curs_set(0);

  int yMax=0,xMax=0;
  getmaxyx(stdscr,yMax,xMax);

  WINDOW *playwin=newwin(20,50,(yMax/2)-10,10);
  box(playwin,0,0);
  refresh();
  wrefresh(playwin);

  initplayer(playwin,1,1,'@');

  // while(getmv()!='x'){
  //   display();
  //   wrefresh(playwin);
  // }

  do{
    display();
    wrefresh(playwin);
  }while(getmv()!='x');

  getch();
  endwin();

  return 0;
}

