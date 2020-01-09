// player.c

#include <ncurses.h>


// #define dec(axis) axis=axis<=1 ? 1 : axis-1
#define dec(axis,max) axis=(axis+max-4)%(max-2)+1;

#define inc(axis,max) axis=(axis)%(max-2)+1;

// private
int yLoc=0;
int xLoc=0;
int yMax=0;
int xMax=0;
char character=' ';
WINDOW *curwin=NULL;
int prevmv=KEY_RIGHT;

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
  // mvwaddch(curwin,yLoc,xLoc,'.');
  mvwaddch(curwin,yLoc,xLoc,' ');
}

void mvup(){
  leavetrail();
  dec(yLoc,yMax);
}

void mvleft(){
  leavetrail();
  dec(xLoc,xMax);
}

void mvdown(){
  leavetrail();
  inc(yLoc,yMax);
}

void mvright(){
  leavetrail();
  inc(xLoc,xMax);
}

int getmv(){ // Return pressed key
  int choice=wgetch(curwin);
  if(choice==ERR)
    choice=prevmv;
  else
    prevmv=choice;
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
