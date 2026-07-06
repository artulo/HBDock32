#ifndef HBDOCKPREVIEW_H
#define HBDOCKPREVIEW_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   RECT Rect;

   int Visible;

} HB_DOCK_PREVIEW;

void hbDockPreviewInit(
   HB_DOCK_PREVIEW * pPreview );

void hbDockPreviewShow(
   HB_DOCK_PREVIEW * pPreview,
   const RECT * pRect );

void hbDockPreviewHide(
   HB_DOCK_PREVIEW * pPreview );

void hbDockPreviewDraw(
   HDC hDC,
   const HB_DOCK_PREVIEW * pPreview );

#ifdef __cplusplus
}
#endif

#endif