#include <windows.h>

#include "hbdockguideredraw.h"

void hbDockGuideRedraw(
   HB_DOCK_GUIDE * pGuide )
{
   if( pGuide == NULL )
      return;

   InvalidateRect(
      pGuide->hWnd,
      NULL,
      TRUE );

   UpdateWindow(
      pGuide->hWnd );
}