#include <windows.h>

#include "hbdockfloatingcaption.h"

void hbDockFloatingSetCaption(
   HB_DOCK_FLOATING_FRAME * pFrame,
   const char * pszCaption )
{
   if( pFrame == NULL )
      return;

   if( pFrame->hWnd == NULL )
      return;

   SetWindowText(
      pFrame->hWnd,
      pszCaption );
}

int hbDockFloatingGetCaption(
   const HB_DOCK_FLOATING_FRAME * pFrame,
   char * pszBuffer,
   int nBuffer )
{
   if( pFrame == NULL )
      return 0;

   if( pFrame->hWnd == NULL )
      return 0;

   return GetWindowText(
      pFrame->hWnd,
      pszBuffer,
      nBuffer );
}