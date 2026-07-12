#include "hbdragpreviewhide.h"

void hbDragPreviewHide(
      HB_DRAG_PREVIEW_CONTROLLER * pController )
{
   hbDockPreviewHide(
      &pController->Overlay );
}