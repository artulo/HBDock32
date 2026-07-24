#ifndef HBDOCKPREVIEWOVERLAY_H
#define HBDOCKPREVIEWOVERLAY_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_PREVIEW_OVERLAY
{
   HWND hWnd;

   HWND hOwner;

   RECT PreviewRect;

   BOOL Visible;

   BYTE Alpha;

} HB_DOCK_PREVIEW_OVERLAY;

BOOL hbDockPreviewOverlayCreate(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay,
   HWND hOwner );

BOOL hbDockPreviewOverlayRegisterClass(
   HINSTANCE hInstance );
   
void hbDockPreviewOverlayDestroy(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay );

void hbDockPreviewOverlayShow(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay,
   const RECT * pRect );

void hbDockPreviewOverlayHide(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay );

void hbDockPreviewOverlayMove(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay,
   const RECT * pRect );

BOOL hbDockPreviewOverlayVisible(
   const HB_DOCK_PREVIEW_OVERLAY * pOverlay );

#ifdef __cplusplus
}
#endif

#endif