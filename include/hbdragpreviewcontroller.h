#ifndef HBDRAGPREVIEWCONTROLLER_H
#define HBDRAGPREVIEWCONTROLLER_H

#include <windows.h>

#include "hbdockpreviewoverlay.h"
#include "hbdockdiamond.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   HB_DOCK_PREVIEW_OVERLAY Overlay;

   HB_DOCK_DIAMOND * pDiamond;

   RECT HostRect;

} HB_DRAG_PREVIEW_CONTROLLER;

BOOL hbDragPreviewControllerInit(
      HB_DRAG_PREVIEW_CONTROLLER * pController,
      HWND hOwner );

void hbDragPreviewControllerDone(
      HB_DRAG_PREVIEW_CONTROLLER * pController );

#ifdef __cplusplus
}
#endif

#endif