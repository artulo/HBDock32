#ifndef HBDOCKMOUSE_H
#define HBDOCKMOUSE_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

int hbDockMouseMoved(
   POINT pt1,
   POINT pt2,
   int cxThreshold,
   int cyThreshold );

#ifdef __cplusplus
}
#endif

#endif