// Player movement

// gcc -g -O0 -Wall -Winline $(pkg-config --libs ncurses) player_main.c player.c

// 09.c

#include <ncurses.h>

int main(){

  initscr();
  noecho();

  // cbreak();
  halfdelay(10);

  int c=0;
  while((c=getch())!='x'){
    printw("%d\n",c);
  }

  endwin();

  return 0;
}

