#include <windows.h>

#include "hbdragpreviewcontroller.h"

BOOL hbDragPreviewControllerInit(
      HB_DRAG_PREVIEW_CONTROLLER * pController,
      HWND hOwner )
{
   ZeroMemory(
      pController,
      sizeof( *pController ) );

   return hbDockPreviewOverlayCreate(
      &pController->Overlay,
      hOwner );
}

void hbDragPreviewControllerDone(
      HB_DRAG_PREVIEW_CONTROLLER * pController )
{
   hbDockPreviewOverlayDestroy(
      &pController->Overlay );
}