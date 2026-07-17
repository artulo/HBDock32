#include <stdlib.h>

#include "hbdockcontainersplit.h"
#include "hbapi.h"

BOOL hbDockContainerSplit(
      HB_DOCK_CONTAINER * pContainer,
      BOOL Vertical )
{
   HB_DOCK_CONTAINER * pFirst;
   HB_DOCK_CONTAINER * pSecond;

   pFirst =
      (HB_DOCK_CONTAINER*)
      calloc(1,sizeof(HB_DOCK_CONTAINER));

   pSecond =
      (HB_DOCK_CONTAINER*)
      calloc(1,sizeof(HB_DOCK_CONTAINER));

   if(!pFirst || !pSecond)
      return FALSE;

   hbDockContainerCreate(
      pFirst,
      NULL);

   hbDockContainerCreate(
      pSecond,
      NULL);

   pContainer->First = pFirst;

   pContainer->Second = pSecond;

   pFirst->Parent = pContainer;

   pSecond->Parent = pContainer;

   pContainer->Type =
      HB_CONTAINER_SPLIT;

   pContainer->Ratio = 0.5f;

   HB_SYMBOL_UNUSED(Vertical);

   return TRUE;
}