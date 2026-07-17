#include <windows.h>

#include "hbdockautohidebuttongeometry.h"

void hbDockAutoHideButtonGetRect(
   const HB_DOCK_AUTOHIDE_BUTTON * pButton,
   RECT * pRect )
{
   if( pButton == NULL || pRect == NULL )
      return;

   *pRect = pButton->Rect;
}

void hbDockAutoHideButtonSetRect(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   const RECT * pRect )
{
   if( pButton == NULL || pRect == NULL )
      return;

   pButton->Rect = *pRect;
}