// player.c

#include <ncurses.h>

// private
int yLoc=0;
int xLoc=0;
int yMax=0;
int xMax=0;
char character=' ';
WINDOW *curwin=NULL;

// public
void initplayer(WINDOW* win,int y,int x,char c){ // Constructor
  curwin=win;
  yLoc=y;
  xLoc=x;
  getmaxyx(curwin,yMax,xMax);
  keypad(curwin,true);
  character=c;
}

void leavetrail(){
  mvwaddch(curwin,yLoc,xLoc,'.');
}

void mvup(){
  leavetrail();
  yLoc= yLoc<=1 ? 1 : yLoc-1 ;
}

void mvleft(){
  leavetrail();
  xLoc= xLoc<=1 ? 1 : xLoc-1 ;
}

void mvdown(){
  leavetrail();
  yLoc= yLoc>=yMax-2 ? yMax-2 : yLoc+1 ;
  // yLoc= yMax-1;
}

void mvright(){
  leavetrail();
  xLoc= xLoc>=xMax-2 ? xMax-2 : xLoc+1 ;
}

int getmv(){ // Return pressed key
  int choice=wgetch(curwin);
  switch(choice){
    case KEY_UP:
      mvup();
      break;
    case KEY_DOWN:
      mvdown();
      break;
    case KEY_LEFT:
      mvleft();
      break;
    case KEY_RIGHT:
      mvright();
      break;
    default:
      break;
  }
  return choice;
}

void display(){
  mvwaddch(curwin,yLoc,xLoc,character);
}
