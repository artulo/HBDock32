#ifndef HBDOCKGEOMETRY_H
#define HBDOCKGEOMETRY_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

void hbDockRectNormalize(
   RECT * pRect );

void hbDockRectOffset(
   RECT * pRect,
   int dx,
   int dy );

void hbDockRectInflate(
   RECT * pRect,
   int dx,
   int dy );

#ifdef __cplusplus
}
#endif

#endif