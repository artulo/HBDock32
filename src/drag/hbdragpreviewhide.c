#include "hbdragpreviewhide.h"
#include "hbdockpreviewoverlay.h"

void hbDragPreviewHide(
      HB_DRAG_PREVIEW_CONTROLLER * pController )
{
   hbDockPreviewOverlayHide(
      &pController->Overlay );
}