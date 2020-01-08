// gcc -g -O0 -Wall -Winline $(pkg-config --libs ncurses) ncurses_casualcoder_04.c

#include <ncurses.h>

int main(){

  // start_ncurses(1,1);
  initscr();

  if(!has_colors()){
    printw("Terminal does not support color");
    getch();
    return -1;
  }
  start_color();
  init_pair(1,COLOR_CYAN,COLOR_WHITE);
  init_pair(2,COLOR_YELLOW,COLOR_MAGENTA);

  if(can_change_color()){
    printw("can change color");
    init_color(COLOR_CYAN,9,999,999); // color,r,g,b
  }

  // Attributes
  // attr_on (3x)
  attron(A_STANDOUT);
  mvprintw(0,0,"This is some standout text");
  attroff(A_STANDOUT);

  attron(A_REVERSE);
  mvprintw(3,3,"This is some reverse text");
  attroff(A_REVERSE);

  mvprintw(6,5,"[");
  attron(A_INVIS);
  mvprintw(6,6,"This is some invisible text");
  attroff(A_INVIS);
  mvprintw(6,33,"]");

  attron(COLOR_PAIR(1));
  mvprintw(9,9,"This is some cyan text");
  attroff(COLOR_PAIR(1));

  attron(COLOR_PAIR(2));
  mvprintw(12,12,"This is some yellow text");
  attroff(COLOR_PAIR(2));

  getch();

  endwin();

  return 0;
}

