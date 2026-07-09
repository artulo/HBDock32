#include "hbdockfloatingswap.h"

int hbDockFloatingSwap(
   HB_DOCK_FLOATING_MANAGER * pManager,
   int nIndex1,
   int nIndex2 )
{
   void * pTemp;

   if( pManager == NULL )
      return 0;

   if( nIndex1 < 0 ||
       nIndex2 < 0 )
      return 0;

   if( nIndex1 >= pManager->Frames.Count )
      return 0;

   if( nIndex2 >= pManager->Frames.Count )
      return 0;

   pTemp =
      pManager->Frames.Items[ nIndex1 ];

   pManager->Frames.Items[ nIndex1 ] =
      pManager->Frames.Items[ nIndex2 ];

   pManager->Frames.Items[ nIndex2 ] =
      pTemp;

   return 1;
}