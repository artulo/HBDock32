#include <windows.h>
 
#include "hbdockcontainerlayout.h"
#include "hbdockcontainer.h"
#include "hbdocktabgroup.h"


void hbLayoutContainer(
   HB_DOCK_CONTAINER * pContainer,
   const RECT * pRect )
{
   if( pContainer == NULL )
      return;

   if( pRect == NULL )
      return;


   pContainer->Rect = *pRect;


   /*
    * El tamaño del contenedor corresponde
    * al área donde se dibuja el grupo de tabs.
    */

   if( pContainer->TabGroup.hWnd != NULL )
   {
      MoveWindow(
         pContainer->TabGroup.hWnd,
         pRect->left,
         pRect->top,
         pRect->right  - pRect->left,
         pRect->bottom - pRect->top,
         TRUE );
   }
}