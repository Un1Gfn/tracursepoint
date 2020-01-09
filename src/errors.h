#ifndef ERR2ORS_H
#define ERR2ORS_H

#include <stdlib.h>
#include <ncurses.h>

#define ERR2 {endwin();printf("ERR2 %s %d\n",__FILE__,__LINE__);exit(1);}

#endif