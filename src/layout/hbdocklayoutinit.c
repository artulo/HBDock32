#include "hbdocklayoutinit.h"

void hbDockLayoutInit(
   HB_DOCK_LAYOUT_TREE * pTree )
{
   if( pTree == NULL )
      return;

   pTree->Root = NULL;
}