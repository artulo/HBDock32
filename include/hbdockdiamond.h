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

} HB_DOCK_DIAMOND_BUTTON;

typedef HB_DOCK_DIAMOND_BUTTON HB_DOCK_DIAMOND_PART;

typedef struct _HB_DOCK_DIAMOND
{
   HWND hWnd;

   HWND hOwner;

   RECT Rect;

   RECT LeftRect;
   RECT RightRect;
   RECT TopRect;
   RECT BottomRect;
   RECT CenterRect;

   BOOL Visible;

} HB_DOCK_DIAMOND;

BOOL hbDockDiamondCreate(
   HB_DOCK_DIAMOND * pDiamond,
   HWND hOwner );

void hbDockDiamondDestroy(
   HB_DOCK_DIAMOND * pDiamond );

void hbDockDiamondShow(
   HB_DOCK_DIAMOND * pDiamond );

void hbDockDiamondHide(
   HB_DOCK_DIAMOND * pDiamond );

void hbDockDiamondMove(
   HB_DOCK_DIAMOND * pDiamond,
   POINT pt );

HB_DOCK_DIAMOND_BUTTON hbDockDiamondHitTest(
   const HB_DOCK_DIAMOND * pDiamond,
   POINT pt );

#ifdef __cplusplus
}
#endif

#endif