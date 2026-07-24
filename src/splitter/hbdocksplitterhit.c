#include <windows.h>

#include "hbdocksplitterhit.h"

BOOL hbDockSplitterHitTest(
      const HB_DOCK_SPLITTER * pSplitter,
      POINT pt )
{
   if( pSplitter == NULL )
      return FALSE;

   return PtInRect(
      &pSplitter->Rect,
      pt );
}