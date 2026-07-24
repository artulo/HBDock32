#include <windows.h>

#include "hbdockautohidetext.h"


int hbDockAutoHideGetTextLength(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   if( pAutoHide->Panel == NULL )
      return 0;

   if( pAutoHide->Panel->hWnd == NULL )
      return 0;

   return GetWindowTextLength(
      pAutoHide->Panel->hWnd );
}


void hbDockAutoHideGetText(
   HB_DOCK_AUTOHIDE * pAutoHide,
   LPTSTR pszText,
   int nSize )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   GetWindowText(
      pAutoHide->Panel->hWnd,
      pszText,
      nSize );
}


void hbDockAutoHideSetText(
   HB_DOCK_AUTOHIDE * pAutoHide,
   LPCTSTR pszText )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   SetWindowText(
      pAutoHide->Panel->hWnd,
      pszText );
}