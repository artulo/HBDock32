#include "hbdockautohideexpand.h"

void hbDockAutoHideExpand(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   pAutoHide->Expanded = 1;

   if( pAutoHide->Panel != NULL )
      pAutoHide->Panel->Rect = pAutoHide->VisibleRect;
}

void hbDockAutoHideCollapse(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   pAutoHide->Expanded = 0;

   if( pAutoHide->Panel != NULL )
      pAutoHide->Panel->Rect = pAutoHide->HiddenRect;
}

int hbDockAutoHideIsExpanded(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   return pAutoHide->Expanded;
}