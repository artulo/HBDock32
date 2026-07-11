#include <windows.h>

#include "hbdockautohidebuttoncheck.h"

void hbDockAutoHideButtonCheck(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   SendMessage(
      pButton->hWnd,
      BM_SETCHECK,
      BST_CHECKED,
      0 );
}

void hbDockAutoHideButtonUncheck(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return;

   SendMessage(
      pButton->hWnd,
      BM_SETCHECK,
      BST_UNCHECKED,
      0 );
}

int hbDockAutoHideButtonIsChecked(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return 0;

   return ( int )
      SendMessage(
         pButton->hWnd,
         BM_GETCHECK,
         0,
         0 ) == BST_CHECKED;
}