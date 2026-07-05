#ifndef HBDOCKPOINT_H
#define HBDOCKPOINT_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

POINT hbDockPoint(
   LONG x,
   LONG y );

int hbDockPointEqual(
   POINT pt1,
   POINT pt2 );

#ifdef __cplusplus
}
#endif

#endif