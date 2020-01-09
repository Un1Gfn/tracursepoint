// Player movement

// gcc -g -O0 -Wall -Winline $(pkg-config --libs ncurses) player_main.c player.c

// 09.c

#include <ncurses.h>

int main(){

  initscr();
  curs_set(0);

  // Fail
  // WINDOW *win=newwin(10,30,0,0);
  // box(win,0,0);
  // refresh();

  // Fail
  // WINDOW *win=newwin(10,30,0,0);
  // box(win,0,0);
  // wrefresh(win);

  // Fail
  // WINDOW *win=newwin(10,30,0,0);
  // box(win,0,0);
  // wrefresh(win);
  // refresh();

  // Succeed
  // WINDOW *win=newwin(10,30,0,0);
  // box(win,0,0);
  // refresh();
  // wrefresh(win);

  // Succeed
  WINDOW *win=newwin(10,30,0,0);
  box(win,0,0);
  wgetch(win);

  getch();
  endwin();

  return 0;
}

