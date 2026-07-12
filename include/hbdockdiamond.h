#ifndef HBDOCKDIAMOND_H
#define HBDOCKDIAMOND_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
   HB_DIAMOND_NONE = 0,
   HB_DIAMOND_LEFT,
   HB_DIAMOND_RIGHT,
   HB_DIAMOND_TOP,
   HB_DIAMOND_BOTTOM,
   HB_DIAMOND_CENTER

} HB_DOCK_DIAMOND_PART;

typedef struct _HB_DOCK_DIAMOND
{
   HWND hWnd;

   RECT Bounds;

   RECT Left;
   RECT Right;
   RECT Top;
   RECT Bottom;
   RECT Center;

   HB_DOCK_DIAMOND_PART HotPart;

   BOOL Visible;

} HB_DOCK_DIAMOND;

#ifdef __cplusplus
}
#endif

#endif