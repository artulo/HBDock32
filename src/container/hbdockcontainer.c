#include <string.h>

#include "hbdockcontainer.h"

BOOL hbDockContainerCreate(
      HB_DOCK_CONTAINER * pContainer,
      HWND hParent )
{
   ZeroMemory(
      pContainer,
      sizeof(*pContainer));
   pContainer->hWnd = hParent;
   pContainer->Type =
      HB_CONTAINER_EMPTY;

   pContainer->Ratio = 0.5f;

   return hbDockTabGroupInit(
      &pContainer->TabGroup);
}

void hbDockContainerDestroy(
      HB_DOCK_CONTAINER * pContainer )
{
   hbDockTabGroupDone(
      &pContainer->TabGroup);
}