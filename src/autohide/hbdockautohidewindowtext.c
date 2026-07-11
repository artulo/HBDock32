#include <windows.h>

#include "hbdockautohidewindowtext.h"

BOOL hbDockAutoHideCopyWindowText(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   LPTSTR pszText,
   int nMax )
{
   if( pPane == NULL )
      return FALSE;

   if( pszText == NULL )
      return FALSE;

   return GetWindowText(
      pPane->hWnd,
      pszText,
      nMax ) >= 0;
}