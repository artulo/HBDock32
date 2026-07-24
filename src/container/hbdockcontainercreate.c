#include <windows.h>

#include "hbdockcontainer.h"

BOOL hbDockContainerCreate(
   HB_DOCK_CONTAINER * pContainer,
   HWND hParent )
{
   if( pContainer == NULL )
      return FALSE;


   ZeroMemory(
      pContainer,
      sizeof( HB_DOCK_CONTAINER ) );


   pContainer->hParent = hParent;


   if( !hbDockTabGroupInit(
          &pContainer->TabGroup ) )
   {
      return FALSE;
   }


   pContainer->Visible = TRUE;


   return TRUE;
}