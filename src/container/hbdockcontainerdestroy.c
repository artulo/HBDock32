#include <windows.h>

#include "hbdockcontainer.h"
#include "hbdockcaptionwindow.h"

void hbDockContainerDestroy(
   HB_DOCK_CONTAINER * pContainer )
{
   if( pContainer == NULL )
      return;


   hbDockTabGroupDone(
      &pContainer->TabGroup );

   hbDockCaptionWindowDestroy(
      pContainer->hWnd );


   ZeroMemory(
      pContainer,
      sizeof( HB_DOCK_CONTAINER ) );
}