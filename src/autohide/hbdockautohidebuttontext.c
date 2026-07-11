#include <windows.h>

#include "hbdockautohidebuttontext.h"

void hbDockAutoHideButtonSetText(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   LPCTSTR pszText )
{
   if( pButton == NULL )
      return;

   SetWindowText(
      pButton->hWnd,
      pszText );
}

int hbDockAutoHideButtonGetText(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   LPTSTR pszText,
   int nMax )
{
   if( pButton == NULL )
      return 0;

   return GetWindowText(
      pButton->hWnd,
      pszText,
      nMax );
}