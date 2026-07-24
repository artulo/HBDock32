#ifndef HBDOCKGUIDEMANAGER_H
#define HBDOCKGUIDEMANAGER_H

#include <windows.h>

#include "hbdockdiamond.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
   HB_GUIDE_NONE = 0,

   HB_GUIDE_LEFT,

   HB_GUIDE_RIGHT,

   HB_GUIDE_TOP,

   HB_GUIDE_BOTTOM,

   HB_GUIDE_CENTER

} HB_DOCK_GUIDE_TYPE;

typedef struct _HB_DOCK_GUIDE
{
   HWND hWnd;

   RECT Rect;

   HB_DOCK_GUIDE_TYPE Type;

   BOOL Visible;

} HB_DOCK_GUIDE;

typedef struct _HB_DOCK_GUIDE_MANAGER
{
   HWND hParent;

   BOOL Visible;

   HB_DOCK_GUIDE Left;

   HB_DOCK_GUIDE Right;

   HB_DOCK_GUIDE Top;

   HB_DOCK_GUIDE Bottom;

   HB_DOCK_GUIDE Center;

   HB_DOCK_DIAMOND Diamond;

} HB_DOCK_GUIDE_MANAGER;

BOOL hbDockGuideManagerCreate(
   HB_DOCK_GUIDE_MANAGER * pManager,
   HWND hParent );

void hbDockGuideManagerDestroy(
   HB_DOCK_GUIDE_MANAGER * pManager );

void hbDockGuideManagerShow(
   HB_DOCK_GUIDE_MANAGER * pManager );

void hbDockGuideManagerHide(
   HB_DOCK_GUIDE_MANAGER * pManager );

void hbDockGuideManagerMove(
   HB_DOCK_GUIDE_MANAGER * pManager,
   POINT pt );

HB_DOCK_GUIDE_TYPE hbDockGuideManagerHitTest(
   const HB_DOCK_GUIDE_MANAGER * pManager,
   POINT pt );

BOOL hbDockGuideManagerVisible(
   const HB_DOCK_GUIDE_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif