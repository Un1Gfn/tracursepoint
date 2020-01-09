// Menu system

#include <ncurses.h>

int main(){

  initscr();
  noecho();
  cbreak();
  curs_set(0);

  int yMax=0,xMax=0;

  getmaxyx(stdscr,yMax,xMax);

  WINDOW *menuwin=newwin(6,xMax-12,yMax-8,5);
  box(menuwin,0,0);
  refresh();
  wrefresh(menuwin);

  keypad(menuwin,true);

  // typedef char *charp;
  // const charp choices[3]={"Walk","Jog","Run"};

  const char (*(choices[3]))={"Walk","Jog","Run"};
  int choice=0;
  int hightlight=0;

  while(1){
    for(int i=0;i!=3;++i){
      if(i==hightlight)
        wattron(menuwin,A_REVERSE);
      mvwprintw(menuwin,i+1,1,choices[i]);
      wattroff(menuwin,A_REVERSE);
    }
    choice=wgetch(menuwin);
    switch(choice){
      case KEY_UP:
        hightlight=(hightlight-1+3)%3;
        break;
      case KEY_DOWN:
        hightlight=(hightlight+1)%3;
        break;
      default:
        break;
    }
    if(choice=='\n')
      break;
  }

  printw("Your choice was: %s",choices[hightlight]);

  getch();
  endwin();

  return 0;
}

