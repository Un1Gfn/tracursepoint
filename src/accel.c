// x.c

#include <X11/extensions/XInput.h>
#include <stdio.h>
#include <string.h>
#include "errors.h"

// XListDeviceProperties (3)
// -> /usr/share/man/man3/XListInputDevices.3.gz
// -> libxi
// -> /usr/lib/pkgconfig/xi.pc

Display *display=NULL;

void init(){
  display=XOpenDisplay(NULL);
}

void delete(){
  XCloseDisplay(display);
  display=NULL;
}

int getdeviceid(const char* str){
  int ndevices=0;
  XDeviceInfo *xdeviceinfos=XListInputDevices(display,&ndevices);
  for(int i=0;i<ndevices;++i)
    if(strcmp(xdeviceinfos[i].name,str)==0){
      int id=xdeviceinfos[i].id;
      free(xdeviceinfos);
      return id;
    }
  ERR2;
}

float get_accel(){

  // getdeviceid("TPPS/2 IBM TrackPoint");

  XDevice *trackpoint=XOpenDevice(display,getdeviceid("TPPS/2 IBM TrackPoint"));
  XCloseDevice(display,trackpoint);

  return 0;

}

// void set_accel(float a){

// }


  // printf("%2lu ",xdeviceinfos[i].id);
  // printf("%3lu ",xdeviceinfos[i].type);

  // const size_t qsz=strlen(xdeviceinfos[i].name)+3;
  // char quoted[qsz];
  // memset(quoted,'\0',qsz*sizeof(char));
  // quoted[0]='\'';
  // strcat(quoted,xdeviceinfos[i].name);
  // strcat(quoted,"\'");

  // printf("%30s ",quoted);
  // printf("%d ",xdeviceinfos[i].num_classes);
  // printf("%d ",xdeviceinfos[i].use);
  // printf("\n");
  

  // printf("%?\n",xdeviceinfos->inputclassinfo);
