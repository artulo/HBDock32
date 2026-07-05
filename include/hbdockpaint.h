#ifndef HBDOCKPAINT_H
#define HBDOCKPAINT_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPaintBackground(
   HDC hDC,
   const RECT * pRect );

void hbDockPaintBorder(
   HDC hDC,
   const RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif