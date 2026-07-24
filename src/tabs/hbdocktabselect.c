#include <windows.h>

#include "hbdocktabselect.h"

#include "hbdocktabgroup.h"
#include "hbdockpanel.h"



BOOL hbDockTabSelect(
   HB_DOCK_TAB_GROUP * pGroup,
   UINT Index )
{
   HB_DOCK_PANEL * pOld;
   HB_DOCK_PANEL * pNew;


   if( pGroup == NULL )
      return FALSE;


   if( Index >= pGroup->Count )
      return FALSE;


   /*
    * Panel actualmente activo.
    */

   pOld =
      hbDockTabGroupGetActivePanel(
         pGroup );


   /*
    * Nuevo panel seleccionado.
    */

   pNew =
      pGroup->Tabs[Index].pPanel;


   if( pNew == NULL )
      return FALSE;


   /*
    * Ocultar panel anterior.
    */

   if( pOld != NULL &&
       pOld != pNew )
   {
      if( pOld->hWnd != NULL )
         ShowWindow(
            pOld->hWnd,
            SW_HIDE );
   }


   /*
    * Cambiar índice activo.
    */

   if( !hbDockTabGroupSetActive(
          pGroup,
          Index ) )
   {
      return FALSE;
   }


   /*
    * Mostrar panel nuevo.
    */

   if( pNew->hWnd != NULL )
   {
      ShowWindow(
         pNew->hWnd,
         SW_SHOW );

      BringWindowToTop(
         pNew->hWnd );
   }


   return TRUE;
}