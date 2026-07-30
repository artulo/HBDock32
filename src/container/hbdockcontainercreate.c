#include <windows.h>

#include "hbdockcontainer.h"
#include "hbdockcaptionwindow.h"

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

   /*
    * Etapa 24: ventana real y propia para la franja de caption (ver
    * hbdockcaptionwindow.c) -- se reusa el campo hWnd del contenedor,
    * que existia en el struct pero nunca se usaba para nada. Si la
    * creacion falla (muy improbable, solo por falta de memoria del
    * sistema), no se aborta el contenedor entero por esto -- el
    * panel simplemente queda sin caption visual, degradando en vez
    * de romper.
    */
   pContainer->hWnd =
      hbDockCaptionWindowCreate(
         hParent );


   return TRUE;
}