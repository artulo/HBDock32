#ifndef HBDOCKPREVIEWRECT_H
#define HBDOCKPREVIEWRECT_H

#include "hbdockpreviewoverlay.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPreviewSetRect(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay,
   const RECT * pRect );

const RECT *
hbDockPreviewGetRect(
   const HB_DOCK_PREVIEW_OVERLAY * pOverlay );

#ifdef __cplusplus
}
#endif

#endif