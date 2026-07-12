#include <stdlib.h>

#include "hbdocklayoutpromote.h"

BOOL hbDockLayoutPromoteChild(
      HB_DOCK_LAYOUT_NODE * pNode )
{
   HB_DOCK_LAYOUT_NODE * pChild;

   if( pNode == NULL )
      return FALSE;

   if( pNode->First != NULL &&
       pNode->Second == NULL )
      pChild = pNode->First;

   else if( pNode->Second != NULL &&
            pNode->First == NULL )
      pChild = pNode->Second;

   else
      return FALSE;

   *pNode = *pChild;

   free( pChild );

   return TRUE;
}