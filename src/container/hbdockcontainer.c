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


   pContainer->pActivePanel = NULL;

   pContainer->Visible = TRUE;


   SetRectEmpty(
      &pContainer->Rect );


   return TRUE;
}



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