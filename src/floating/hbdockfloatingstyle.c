#include <windows.h>

#include "hbdockfloatingstyle.h"

void hbDockFloatingSetStyle(
   HB_DOCK_FLOATING_FRAME * pFrame,
   DWORD dwStyle )
{
   if( pFrame == NULL )
      return;

   pFrame->Style = dwStyle;

   if( pFrame->hWnd != NULL )
      SetWindowLong(
         pFrame->hWnd,
         GWL_STYLE,
         ( LONG ) dwStyle );
}

DWORD hbDockFloatingGetStyle(
   const HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return 0;

   return pFrame->Style;
}

void hbDockFloatingSetExStyle(
   HB_DOCK_FLOATING_FRAME * pFrame,
   DWORD dwStyle )
{
   if( pFrame == NULL )
      return;

   pFrame->ExStyle = dwStyle;

   if( pFrame->hWnd != NULL )
      SetWindowLong(
         pFrame->hWnd,
         GWL_EXSTYLE,
         ( LONG ) dwStyle );
}

DWORD hbDockFloatingGetExStyle(
   const HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return 0;

   return pFrame->ExStyle;
}