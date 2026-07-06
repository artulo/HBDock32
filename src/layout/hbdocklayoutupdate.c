#include <windows.h>

#include "hbdocklayoutupdate.h"

void hbDockLayoutUpdate(
   HB_DOCK_LAYOUT_ENGINE * pEngine,
   HWND hWnd )
{
   RECT rc;

   if( pEngine == NULL )
      return;

   if( pEngine->Root == NULL )
      return;

   GetClientRect(
      hWnd,
      &rc );

   hbDockLayoutEnginePerform(
      pEngine,
      &rc );

   InvalidateRect(
      hWnd,
      NULL,
      TRUE );
}