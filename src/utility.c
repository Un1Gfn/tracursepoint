// utility.c

#include <stdio.h>
#include <stdlib.h>
// #include <errno.h>
#include "errors.h"

// /sys/devices/platform/i8042/serio1/sensitivity
// /sys/devices/platform/i8042/serio1/speed

// [0, 255] default 200
int get_sensitivity(){
  FILE *pFile;  
  if (!(pFile=fopen ("/sys/devices/platform/i8042/serio1/sensitivity","r")))
    ERR2;
  int ret=0;
  fscanf(pFile,"%d",&ret);
  fclose(pFile);
  return ret;
}

// [0, 255] default 97
int get_speed(){
  FILE *pFile;
  if (!(pFile=fopen ("/sys/devices/platform/i8042/serio1/speed","r")))
    ERR2;
  int ret=0;
  fscanf(pFile,"%d",&ret);
  fclose(pFile);
  return ret;
}

// // return ferror() value
// // int set_sensitivity(int s){
// void set_sensitivity(int s){
//   FILE *pFile;  
//   if (!(pFile=fopen ("/sys/devices/platform/i8042/serio1/sensitivity","w")))
//     ERR2;

//   // bash: echo: write error: Numerical result out of range
//   // bash: echo: write error: Invalid argument
//   // 

//   // int errno_keep=0;
//   // int ferror_keep=0;
//   // errno=0;

//   // fprintf(pFile,"%d\n",s);
//   // errno_keep=errno;
//   // ferror_keep=ferror(pFile);

//   // errno=0;
//   // clearerr(pFile);
//   // printf("%d %d - %d %d\n",s,get_sensitivity(),errno_keep,ferror_keep);

//   // 150 150 - 0 0
//   // 149 149 - 0 0
//   // 999 149 - 0 0
//   // -1 149 - 0 0
//   // 150 150 - 0 0

//   fclose(pFile);

// }

// void set_speed(int s){
//   FILE *pFile;  
//   if (!(pFile=fopen ("/sys/devices/platform/i8042/serio1/speed","w")))
//     ERR2;
//   fclose(pFile);
// }

