#ifndef SLIDER_H
#define SLIDER_H

// #define RANGE  80
#define RANGE 255 // [0, 255]
#define HEIGHT 5
#define WIDTH RANGE+1+2+2

#define SLGROOVE '-'
#define SLHANDLE ' ' // Space in reverse color

bool validval(int val);
bool validxpos(int ypos);

int to_xpos(int val);
int to_val(int pos);

void slider_init(WINDOW *slider,int val_initial);
void slider_update(WINDOW *slider,int val_new);

#endif