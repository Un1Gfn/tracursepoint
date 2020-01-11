// x.c

#include <X11/extensions/XInput.h>
#include <X11/Xatom.h>
#include <stdio.h>
#include <string.h>
#include "errors.h"
// #include "accel.h"

#define SOMESIZE 100

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

  // int nprops=0;
  // Atom *atoms=XListDeviceProperties(display,trackpoint,&nprops);
  // for(int i=0;i<nprops;++i){
  //   char *name=XGetAtomName(display,atoms[i]);
  //   printf("%4lu %s\n",atoms[i],name);
  //   XFree(name);
  // }

  // char **names=calloc(SOMESIZE,sizeof(char *));
  // XGetAtomNames(display,atoms,nprops,names);
  // Atom property=0;
  // for(int i=0;i<nprops;++i){
  //   if(strcmp(names[i],"libinput Accel Speed")==0)
  //     property=atoms[i];
  //   // printf("%4lu %s\n",atoms[i],names[i]);
  //   XFree(names[i]);
  //   names[i]=NULL;
  // }
  // free(names);
  // names=NULL;
  // XFree(atoms);
  // atoms=NULL;

  // "libinput Accel Speed" (305)
  const Atom property=XInternAtom(display,"libinput Accel Speed",True);
  // printf("%lu\n",property);

  // https://www.x.org/releases/current/doc/libX11/libX11/libX11.html#Properties_and_Atoms
  // printf("%lu %s\n",XA_INTEGER,XGetAtomName(display,XA_INTEGER));
  Atom actual_type_return=0;
  int actual_format_return=0;
  unsigned long nitems_return=0;
  unsigned long bytes_after_return=0;
  // unsigned char *prop_return=calloc(SOMESIZE,sizeof(unsigned char));
  unsigned char *prop_return=NULL;
  // printf("%p\n",prop_return);
  // Defined in /usr/include/X11/Xatom.h
  // Atom req_type=XA_INTEGER;
  const long offset=0;
  const long length=1; // 1 x 32 = 32 bits
  Atom req_type=AnyPropertyType;
  XGetDeviceProperty(
    display,
    trackpoint,
    property,
    offset,
    length,
    False, // not deleted
    req_type,
    &actual_type_return,
    &actual_format_return,
    &nitems_return,
    &bytes_after_return,
    &prop_return
  );

  // printf("%p\n",prop_return);
  // printf("%zu(x8) %zu(x8) - %ld(x32) %ld(x32) - %s %d(x1) %lu %lu(x8) \n",
  //   sizeof(float),
  //   sizeof(double),
  //   offset,
  //   length,
  //   XGetAtomName(display,actual_type_return),
  //   actual_format_return,
  //   nitems_return,
  //   bytes_after_return,
  // );

  float ret=*((float *)prop_return);
  free(prop_return);
  prop_return=NULL;
  return ret;

}