#ifndef HBDOCKRECT_H
#define HBDOCKRECT_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

RECT hbDockRect(
   LONG Left,
   LONG Top,
   LONG Right,
   LONG Bottom );

int hbDockRectEqual(
   const RECT * pRect1,
   const RECT * pRect2 );

#ifdef __cplusplus
}
#endif

#endif