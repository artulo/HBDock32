#include <windows.h>

#include "hbdockautohidetext.h"

int hbDockAutoHideGetTextLength(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return GetWindowTextLength(
      pPane->hWnd );
}

void hbDockAutoHideGetText(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   LPTSTR pszText,
   int nSize )
{
   if( pPane == NULL )
      return;

   GetWindowText(
      pPane->hWnd,
      pszText,
      nSize );
}

void hbDockAutoHideSetText(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   LPCTSTR pszText )
{
   if( pPane == NULL )
      return;

   SetWindowText(
      pPane->hWnd,
      pszText );
}