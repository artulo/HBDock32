#include <windows.h>

#include "hbdockdraghittest.h"
#include "hbdockdragcontroller.h"
#include "hbdockguidemanager.h"

HB_DOCK_GUIDE_TYPE hbDockDragHitTest(
   HB_DOCK_DRAG_CONTROLLER * pController )
{
   POINT pt;
   BOOL FromDiamond;
   HB_DOCK_GUIDE_TYPE Guide;

   if( pController == NULL )
      return HB_GUIDE_NONE;

   if( pController->pManager == NULL )
      return HB_GUIDE_NONE;

   if( !pController->Drag.Dragging )
      return HB_GUIDE_NONE;

   pt = pController->Drag.CurrentPoint;

   Guide =
      hbDockGuideManagerHitTestEx(
         &pController->pManager->GuideManager,
         pt,
         &FromDiamond );

   pController->Drag.GuideSource =
      ( Guide == HB_GUIDE_NONE ) ?
         HB_DOCK_GUIDE_SOURCE_NONE :
         ( FromDiamond ?
              HB_DOCK_GUIDE_SOURCE_DIAMOND :
              HB_DOCK_GUIDE_SOURCE_OUTER );

   return Guide;
}