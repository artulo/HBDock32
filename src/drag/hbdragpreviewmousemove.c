#include "hbdragpreviewmousemove.h"

#include "hbdockdiamondhit.h"

#include "hbdragpreviewhide.h"
#include "hbdragpreviewupdate.h"

void hbDragPreviewMouseMove(
      HB_DRAG_PREVIEW_CONTROLLER * pController,
      POINT pt )
{
   HB_DOCK_DIAMOND_PART Part;

   Part =
      hbDockDiamondHitTest(
         pController->pDiamond,
         pt );

   if( Part == HB_DIAMOND_NONE )
   {
      hbDragPreviewHide(
         pController );

      return;
   }

   hbDragPreviewUpdate(
      pController,
      Part );
}