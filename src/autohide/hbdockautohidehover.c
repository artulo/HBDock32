#include "hbdockautohidehover.h"

void hbDockAutoHideBeginHover(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Hover = TRUE;
}


void hbDockAutoHideEndHover(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Hover = FALSE;
}


int hbDockAutoHideIsHover(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return FALSE;

   return pAutoHide->Hover;
}