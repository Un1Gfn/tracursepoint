// 01_02.c

#include <ncurses.h>

int main(){

  initscr();

  int x=10,y=10;

  move(y,x); // cursor

  printw("Hello World!");

  // refresh(); // Memory -> Screen

  int c=getch();
  clear(); // Clear the StandardScreen

  mvprintw(0,0,"%d",c);
  refresh();


  getch();

  endwin(); // Deallocate

  // int a=getch();
  // printf("\n%d\n",a);

  return 0;
}