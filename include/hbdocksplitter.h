#ifndef HBDOCKSPLITTER_H
#define HBDOCKSPLITTER_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HB_DOCK_SPLITTER_SIZE 4

typedef struct _HB_DOCK_SPLITTER
{
   RECT Rect;

   int Visible;

   int Vertical;

   int Tracking;

} HB_DOCK_SPLITTER;

void hbDockSplitterInit(
   HB_DOCK_SPLITTER * pSplitter );

void hbDockSplitterSetRect(
   HB_DOCK_SPLITTER * pSplitter,
   const RECT * pRect );

void hbDockSplitterDraw(
   HDC hDC,
   const HB_DOCK_SPLITTER * pSplitter );

int hbDockSplitterHitTest(
   const HB_DOCK_SPLITTER * pSplitter,
   POINT pt );

#ifdef __cplusplus
}
#endif

#endif