#include <windows.h>

#include "hbdockdraghittest.h"
#include "hbdockdragcontroller.h"
#include "hbdockguidemanager.h"

HB_DOCK_GUIDE_TYPE hbDockDragHitTest(
   HB_DOCK_DRAG_CONTROLLER * pController )
{
   POINT pt;

   if( pController == NULL )
      return HB_GUIDE_NONE;

   if( pController->pManager == NULL )
      return HB_GUIDE_NONE;

   if( !pController->Drag.Dragging )
      return HB_GUIDE_NONE;

   pt = pController->Drag.CurrentPoint;

   return hbDockGuideManagerHitTest(
      &pController->pManager->GuideManager,
      pt );
}