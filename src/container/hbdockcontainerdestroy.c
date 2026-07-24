#include <windows.h>

#include "hbdockcontainer.h"

void hbDockContainerDestroy(
   HB_DOCK_CONTAINER * pContainer )
{
   if( pContainer == NULL )
      return;


   hbDockTabGroupDone(
      &pContainer->TabGroup );


   ZeroMemory(
      pContainer,
      sizeof( HB_DOCK_CONTAINER ) );
}