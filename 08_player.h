#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>

// public
void initplayer(WINDOW* win,int y,int x,char c); // Constructor
void mvup();
void mvdown();
void mvleft();
void mvright();
int getmv();
void display();

#endif