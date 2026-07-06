#include <windows.h>

#include "hbdockrender.h"

void hbDockRenderPanel(
   HDC hDC,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_THEME * pTheme )
{
   HBRUSH hBrush;

   RECT rc;

   rc = pPanel->Rect;

   hBrush = CreateSolidBrush(
      pTheme->Background );

   FillRect(
      hDC,
      &rc,
      hBrush );

   DeleteObject(
      hBrush );

   FrameRect(
      hDC,
      &rc,
      ( HBRUSH ) GetStockObject(
         BLACK_BRUSH ) );
}