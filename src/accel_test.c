// x_test.c

// gcc -std=c11 -g -O0 -Wall -Wextra -Winline -fdiagnostics-color=always $(pkg-config --libs xi x11 ncurses) accel.c accel_test.c

#include <stdio.h>
#include "accel.h"

int main(){

  // https://xcb.freedesktop.org/tutorial/#requestsandreplies:thexlibkillers
  // XOpenDisplay(3):
  // if the display_name is NULL, it defaults to the value ofthe DISPLAY environment variable.
  init();

  // printf("%d\n",getdeviceid("AT Translated Set 2 keyboard"));
  // printf("%d\n",getdeviceid("TPPS/2 IBM TrackPoint"));
  get_accel();

  // int nprops=0;
  // Atom* atom=XListDeviceProperties(display,trackpoint,&nprops);
  // for(int i=0;i<nprops;++i)
  //   printf("%lu\n",atom[i]);

  // XCloseDevice(display,trackpoint);


  // for(int i=0;i<devices;++i){
  //   if(strcmp((xdeviceinfos[i].name,"AT Translated Set 2 keyboard")==0){
  //     printf("%2lu ",(xdeviceinfos[i].id);
  //     printf("%3lu ",(xdeviceinfos[i].type);
  //     // char quoted[strlen((xdeviceinfos[i].name)+3]={'\''};
  //     const size_t qsz=strlen((xdeviceinfos[i].name)+3;
  //     char quoted[qsz];
  //     memset(quoted,'\0',qsz*sizeof(char));
  //     quoted[0]='\'';
  //     strcat(quoted,(xdeviceinfos[i].name);
  //     strcat(quoted,"\'");
  //     printf("%30s ",quoted);
  //     printf("%d ",(xdeviceinfos[i].num_classes);
  //     printf("%d ",(xdeviceinfos[i].use);
  //     printf("\n");
  //     // printf("%?\n",xdeviceinfos->inputclassinfo);
  //   }
  // }

  delete();

  return 0;

}

