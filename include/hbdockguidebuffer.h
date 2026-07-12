#ifndef HBDOCKGUIDEBUFFER_H
#define HBDOCKGUIDEBUFFER_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

HDC hbDockGuideBeginPaintBuffer(
   HDC hDC,
   RECT * pRect,
   HBITMAP * phBitmap );

void hbDockGuideEndPaintBuffer(
   HDC hScreen,
   HDC hBuffer,
   RECT * pRect,
   HBITMAP hBitmap );

#ifdef __cplusplus
}
#endif

#endif