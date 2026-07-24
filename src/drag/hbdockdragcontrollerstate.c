#include <windows.h>

#include "hbdockdragcontroller.h"

BOOL hbDockDragIsDragging(
   const HB_DOCK_DRAG_CONTROLLER * pController )
{
   if( pController == NULL )
      return FALSE;

   return pController->Drag.Dragging;
}

HB_DOCK_PANEL * hbDockDragGetPanel(
   const HB_DOCK_DRAG_CONTROLLER * pController )
{
   if( pController == NULL )
      return NULL;

   return pController->pPanel;
}

POINT hbDockDragGetPoint(
   const HB_DOCK_DRAG_CONTROLLER * pController )
{
   POINT pt;

   pt.x = 0;
   pt.y = 0;

   if( pController == NULL )
      return pt;

   return pController->Drag.CurrentPoint;
}

RECT hbDockDragGetRect(
   const HB_DOCK_DRAG_CONTROLLER * pController )
{
   RECT rc;

   SetRectEmpty(
      &rc );

   if( pController == NULL )
      return rc;

   return pController->Drag.DragRect;
}

HWND hbDockDragGetSourceWindow(
   const HB_DOCK_DRAG_CONTROLLER * pController )
{
   if( pController == NULL )
      return NULL;

   return pController->Drag.hWndSource;
}