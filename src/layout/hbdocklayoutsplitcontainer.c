#include <stdlib.h>

#include "hbdocklayoutsplitcontainer.h"
#include "hbdockcontainer.h"

BOOL hbDockLayoutSplitContainer(
      HB_DOCK_LAYOUT_NODE * pNode,
      BOOL Vertical )
{
   HB_DOCK_CONTAINER * pOld;
   HB_DOCK_CONTAINER * pFirst;
   HB_DOCK_CONTAINER * pSecond;

   if( pNode == NULL )
      return FALSE;

   pOld = pNode->pContainer;

   pFirst =
      (HB_DOCK_CONTAINER*)
      calloc(1,sizeof(HB_DOCK_CONTAINER));

   pSecond =
      (HB_DOCK_CONTAINER*)
      calloc(1,sizeof(HB_DOCK_CONTAINER));

   if( pFirst == NULL || pSecond == NULL )
      return FALSE;

   *pFirst = *pOld;

   hbDockContainerCreate(
      pSecond,
      NULL);

   pNode->pContainer = NULL;

   pNode->First =
      hbDockLayoutCreateLeaf(NULL);

   pNode->Second =
      hbDockLayoutCreateLeaf(NULL);

   pNode->First->pContainer = pFirst;
   pNode->Second->pContainer = pSecond;

   pNode->Ratio = 0.5f;

   pNode->Type =
      Vertical ?
      HB_LAYOUT_VERTICAL :
      HB_LAYOUT_HORIZONTAL;

   return TRUE;
}