// 05.c

#include <ncurses.h>

int main(){

  initscr();
  cbreak();
  noecho();
  int y=0,x=0,yBeg=0,xBeg=0,yMax=0,xMax=0;



  // const int margin=5;
  // getmaxyx(stdscr,yMax,xMax);
  // WINDOW *win=newwin(yMax-margin-margin,xMax-margin-margin,margin,margin);
  // refresh();
  // box(win,0,0);
  // wrefresh(win);

  // // https://zh.moegirl.org/zh-hant/%E6%9C%9D%E4%BB%93%E9%9F%B3%E5%BF%83
  // // Brain Power
  // printw("AAAAE-A-A-I-A-U- JO");
  // refresh();
  // wprintw(win,"EEEEO-A-AAA-AAAA");
  // wrefresh(win);
  // move(9,9);
  // wmove(win,9,9);
  // printw("e-eee-ee-eee");
  // refresh();
  // wprintw(win,"oooooooooo");
  // wrefresh(win);



  WINDOW *win=newwin(10,20,10,10);
  refresh();

  box(win,0,0);
  wrefresh(win);

  // stdscr: the Standard Screen
  // getyx(3): All of these interfaces are macros.  A "&" is not necessary before the variables y and x.
  getyx(stdscr,y,x);
  getbegyx(win,yBeg,xBeg);
  getmaxyx(stdscr,yMax,xMax);

  // mvprintw(yMax/2,xMax/2,"hello");
  move(yMax/2,xMax/2);
  printw("hello");
  printw("%d %d %d %d %d %d",y,x,yBeg,xBeg,yMax,xMax);
  refresh();



  getch();
  endwin();

  return 0;
}

