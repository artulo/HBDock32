#include <stdlib.h>

#include "hbdocklayoutremoveempty.h"
#include "hbdockcontainer.h"

BOOL hbDockLayoutRemoveEmpty(
      HB_DOCK_LAYOUT_NODE * pNode )
{
   if( pNode == NULL )
      return FALSE;

   if( pNode->Type != HB_LAYOUT_LEAF )
      return FALSE;

   if( pNode->pContainer == NULL )
      return TRUE;

   if( pNode->pContainer->Type ==
       HB_CONTAINER_EMPTY )
   {
      free(
         pNode->pContainer );

      pNode->pContainer = NULL;

      return TRUE;
   }

   return FALSE;
}