#include "hbdockfloatingcompare.h"

int hbDockFloatingCompareHandle(
   const HB_DOCK_FLOATING_FRAME * pLeft,
   const HB_DOCK_FLOATING_FRAME * pRight )
{
   if( pLeft->hWnd < pRight->hWnd )
      return -1;

   if( pLeft->hWnd > pRight->hWnd )
      return 1;

   return 0;
}

int hbDockFloatingComparePanelId(
   const HB_DOCK_FLOATING_FRAME * pLeft,
   const HB_DOCK_FLOATING_FRAME * pRight )
{
   unsigned int nLeft;
   unsigned int nRight;

   nLeft =
      pLeft->Panel ?
      pLeft->Panel->Id : 0;

   nRight =
      pRight->Panel ?
      pRight->Panel->Id : 0;

   if( nLeft < nRight )
      return -1;

   if( nLeft > nRight )
      return 1;

   return 0;
}