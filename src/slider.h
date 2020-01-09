#ifndef SLIDER_H
#define SLIDER_H

// #define RANGE  80
#define RANGE 255 // [0, 255]

#define SLGROOVE '-'
#define SLHANDLE ' ' // Space in reverse color

void slider_init(WINDOW *slider,int initial);
void slider_update(WINDOW *slider,int new);

#endif