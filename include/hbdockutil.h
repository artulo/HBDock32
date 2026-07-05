#ifndef HBDOCKUTIL_H
#define HBDOCKUTIL_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

void hbDockCopyRect(
   RECT * pDst,
   const RECT * pSrc );

int hbDockRectWidth(
   const RECT * pRect );

int hbDockRectHeight(
   const RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif