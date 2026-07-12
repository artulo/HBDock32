#include "hbdocksplittermove.h"

#define HB_LAYOUT_MIN_RATIO 0.10f
#define HB_LAYOUT_MAX_RATIO 0.90f

void hbDockSplitterMove(
      HB_DOCK_SPLITTER * pSplitter,
      POINT pt )
{
   RECT rc;
   float ratio;

   if( pSplitter == NULL )
      return;

   rc = pSplitter->pNode->Rect;

   if( pSplitter->pNode->Type ==
       HB_LAYOUT_VERTICAL )
   {
      ratio =
         (float)( pt.x - rc.left ) /
         (float)( rc.right - rc.left );
   }
   else
   {
      ratio =
         (float)( pt.y - rc.top ) /
         (float)( rc.bottom - rc.top );
   }

   if( ratio < HB_LAYOUT_MIN_RATIO )
      ratio = HB_LAYOUT_MIN_RATIO;

   if( ratio > HB_LAYOUT_MAX_RATIO )
      ratio = HB_LAYOUT_MAX_RATIO;

   pSplitter->pNode->Ratio = ratio;
}