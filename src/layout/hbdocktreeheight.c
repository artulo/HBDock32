#include "hbdocktreeheight.h"

int hbDockTreeHeight(
   HB_DOCK_NODE * pRoot )
{
   int h1;
   int h2;

   if( pRoot == NULL )
      return 0;

   h1 = hbDockTreeHeight(
      pRoot->First );

   h2 = hbDockTreeHeight(
      pRoot->Second );

   if( h1 > h2 )
      return h1 + 1;

   return h2 + 1;
}