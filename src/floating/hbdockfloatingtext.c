#include <windows.h>

#include "hbdockfloatingtext.h"

int hbDockFloatingGetTextLength(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return 0;

   if( pFrame->hWnd == NULL )
      return 0;

   return GetWindowTextLength(
      pFrame->hWnd );
}

void hbDockFloatingGetText(
   HB_DOCK_FLOATING_FRAME * pFrame,
   char * pszText,
   int nSize )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd == NULL )
      return;

   GetWindowText(
      pFrame->hWnd,
      pszText,
      nSize );
}