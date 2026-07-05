#include <windows.h>

#include "hbdocktracker.h"

static void hbDockTrackerDrawXor(
   HDC hDC,
   const RECT * pRect )
{
   HBRUSH hBrush;

   hBrush = ( HBRUSH ) GetStockObject(
      NULL_BRUSH );

   SelectObject(
      hDC,
      hBrush );

   PatBlt(
      hDC,
      pRect->left,
      pRect->top,
      pRect->right - pRect->left,
      pRect->bottom - pRect->top,
      PATINVERT );
}

void hbDockTrackerInit(
   HB_DOCK_TRACKER * pTracker )
{
   if( pTracker == NULL )
      return;

   ZeroMemory(
      pTracker,
      sizeof( HB_DOCK_TRACKER ) );
}

void hbDockTrackerShow(
   HDC hDC,
   HB_DOCK_TRACKER * pTracker,
   const RECT * pRect )
{
   if( hDC == NULL || pTracker == NULL || pRect == NULL )
      return;

   if( pTracker->Visible )
      hbDockTrackerDrawXor(
         hDC,
         &pTracker->Frame );

   pTracker->Frame = *pRect;
   pTracker->Visible = 1;

   hbDockTrackerDrawXor(
      hDC,
      &pTracker->Frame );
}

void hbDockTrackerHide(
   HDC hDC,
   HB_DOCK_TRACKER * pTracker )
{
   if( hDC == NULL || pTracker == NULL )
      return;

   if( !pTracker->Visible )
      return;

   hbDockTrackerDrawXor(
      hDC,
      &pTracker->Frame );

   pTracker->Visible = 0;
}