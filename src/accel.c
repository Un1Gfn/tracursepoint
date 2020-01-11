// x.c

#include <X11/extensions/XInput.h>
#include <stdio.h>
#include <string.h>
#include "errors.h"
// #include "accel.h"

#define NAMEARRSZ 100

// XListDeviceProperties (3)
// -> /usr/share/man/man3/XListInputDevices.3.gz
// -> libxi
// -> /usr/lib/pkgconfig/xi.pc

Display *display=NULL;
XDevice *trackpoint=NULL;

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

  // printf("%2lu ",xdeviceinfos[i].id);
  // printf("%3lu ",xdeviceinfos[i].type);

  // const size_t qsz=strlen(xdeviceinfos[i].name)+3;
  // char quoted[qsz];
  // // https://stackoverflow.com/a/3082971/8243991
  // memset(quoted,'\0',qsz*sizeof(char));
  // quoted[0]='\'';
  // strcat(quoted,xdeviceinfos[i].name);
  // strcat(quoted,"\'");

  // printf("%30s ",quoted);
  // printf("%d ",xdeviceinfos[i].num_classes);
  // printf("%d ",xdeviceinfos[i].use);
  // printf("\n");

  // printf("%?\n",xdeviceinfos->inputclassinfo);
}

void open_accel(){
  // https://xcb.freedesktop.org/tutorial/#requestsandreplies:thexlibkillers
  // XOpenDisplay(3):
  // if the display_name is NULL, it defaults to the value ofthe DISPLAY environment variable.
  display=XOpenDisplay(NULL);
  trackpoint=XOpenDevice(display,getdeviceid("TPPS/2 IBM TrackPoint"));
}

void close_accel(){
  XCloseDevice(display,trackpoint);
  trackpoint=NULL;
  XCloseDisplay(display);
  display=NULL;
}

float get_accel(){

  int nprops=0;
  Atom* atoms=XListDeviceProperties(display,trackpoint,&nprops);

  // No memry error
  // for(int i=0;i<nprops;++i){
  //   char *name=XGetAtomName(display,atoms[i]);
  //   printf("%4lu %s\n",atoms[i],name);
  //   XFree(name);
  // }

  // char **names=NULL;
  // char names[NAMEARRSZ][NAMEARRSZ]={};
  // char *names=calloc(NAMEARRSZ*NAMEARRSZ,sizeof(char));
  char *names[NAMEARRSZ]={};
  XGetAtomNames(display,atoms,nprops,&names);
  // for(int i=0;i<nprops;++i){
    // printf("%4lu %s\n",atoms[i],names[i]);
    // XFree(names[i]);
    // names[i]=NULL;
  // }
  // XFree(names);
  // names=NULL;

  // XListDeviceProperties(3):
  // The client is expected to free the list of properties using XFree
  XFree(atoms);

  return 0;

}