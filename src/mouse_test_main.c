#include <ncurses.h>
#include <stdlib.h>

#define ERR2 {endwin();printf("ERR2 %s %d\n",__FILE__,__LINE__);exit(1);}

int main(){

  initscr();
  cbreak();
  noecho();
  // curs_set(0);
  keypad(stdscr,1);

  // printw("%X\n",BUTTON1_CLICKED);
  // printw("%X\n",BUTTON2_CLICKED);
  // printw("%X\n",BUTTON3_CLICKED);
  // mmask_t newmask=mousemask(BUTTON1_CLICKED|BUTTON2_CLICKED|BUTTON3_CLICKED,NULL);
  // printw("%X\n",BUTTON1_CLICKED|BUTTON2_CLICKED|BUTTON3_CLICKED);
  // printw("%X\n",newmask);

  // mousemask(0,NULL);
  mousemask(BUTTON1_PRESSED,NULL);
  // mousemask(BUTTON1_CLICKED|BUTTON2_CLICKED|BUTTON3_CLICKED,NULL);
  // mousemask(ALL_MOUSE_EVENTS,NULL);

  printw("%X\n\n",KEY_MOUSE);

  while(1){
    int ch=wgetch(stdscr);
    // printw("%X\n",ch);
    if(ch=='x')
      break;
    if(ch==KEY_MOUSE){
      MEVENT event={};
      if(getmouse(&event)!=OK)
        ERR2;
      printw("%d (%d, %d, %d) %X\n",
        event.id,
        event.y,
        event.x,
        event.z,
        event.bstate
      );
    }
  }

  // getch();
  endwin();

  return(0);

}