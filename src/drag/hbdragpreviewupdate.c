#include "hbdragpreviewupdate.h"

#include "hbdragpreviewcalc.h"
#include "hbdockpreviewrect.h"
#include "hbdockpreviewshow.h"

void hbDragPreviewUpdate(
      HB_DRAG_PREVIEW_CONTROLLER * pController,
      HB_DOCK_DIAMOND_PART Part )
{
   RECT rc;

   hbDragPreviewCalcRect(
      &pController->HostRect,
      Part,
      &rc );

   hbDockPreviewSetRect(
      &pController->Overlay,
      &rc );

   hbDockPreviewShow(
      &pController->Overlay );
}