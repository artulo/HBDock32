#include <windows.h>

#include "hbdockautohidewindowtext.h"


BOOL hbDockAutoHideCopyWindowText(
   HB_DOCK_AUTOHIDE * pAutoHide,
   LPTSTR pszText,
   int nMax )
{
   if( pAutoHide == NULL )
      return FALSE;

   if( pAutoHide->Panel == NULL )
      return FALSE;

   if( pAutoHide->Panel->hWnd == NULL )
      return FALSE;

   if( pszText == NULL )
      return FALSE;


   return GetWindowText(
      pAutoHide->Panel->hWnd,
      pszText,
      nMax ) >= 0;
}