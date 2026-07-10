#include "hbdockautohidepanerect.h"

void hbDockAutoHidePaneSetRect(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   const RECT * pRect )
{
   if( pPane == NULL || pRect == NULL )
      return;

   pPane->Rect = *pRect;
}

void hbDockAutoHidePaneGetRect(
   const HB_DOCK_AUTOHIDE_PANE * pPane,
   RECT * pRect )
{
   if( pPane == NULL || pRect == NULL )
      return;

   *pRect = pPane->Rect;
}