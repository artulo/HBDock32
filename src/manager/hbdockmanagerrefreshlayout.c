#include <windows.h>

#include "hbdockmanagerrefreshlayout.h"

#include "hbdocklayoutremoveempty.h"
#include "hbdocklayoutoptimizer.h"
#include "hbdocklayoutrecalc.h"
#include "hbdockmanagerautohide.h"


BOOL hbDockManagerRefreshLayout(
   HB_DOCK_MANAGER * pManager )
{
   RECT rcClient;


   if( pManager == NULL )
      return FALSE;

   if( pManager->hMainWnd == NULL )
      return FALSE;


   /*
    * Compactar el árbol.
    */
   hbDockLayoutRemoveEmpty(
      &pManager->LayoutTree,
      pManager->LayoutTree.Root );


   /*
    * Optimizar el árbol.
    */
   hbDockLayoutOptimize(
      &pManager->LayoutTree );


   /*
    * Obtener el área cliente.
    */
   GetClientRect(
      pManager->hMainWnd,
      &rcClient );

   /*
    * Etapa 37: reservar el espacio de la toolbar (u otra barra),
    * que GetClientRect no excluye por su cuenta -- ver nota en
    * hbdockmanager.h.
    */
   rcClient.top += pManager->TopMargin;

   if( rcClient.top > rcClient.bottom )
      rcClient.top = rcClient.bottom;

   /*
    * Etapa 65: ver nota identica en hbdockmanagerlayout.c.
    */
   {
      int nAHLeft, nAHTop, nAHRight, nAHBottom;

      hbDockManagerGetAutoHideMargins(
         pManager,
         &nAHLeft, &nAHTop, &nAHRight, &nAHBottom );

      rcClient.left   += nAHLeft;
      rcClient.top    += nAHTop;
      rcClient.right  -= nAHRight;
      rcClient.bottom -= nAHBottom;

      if( rcClient.left > rcClient.right )
         rcClient.right = rcClient.left;

      if( rcClient.top > rcClient.bottom )
         rcClient.bottom = rcClient.top;
   }


   /*
    * Recalcular el layout.
    */
   hbDockLayoutRecalc(
      &pManager->LayoutTree,
      &rcClient,
      ( void * ) pManager );


   /*
    * Repintar.
    *
    * Nota de estabilizacion: InvalidateRect solo invalida la ventana
    * que se le pasa -- NO baja automaticamente a las ventanas hijas
    * (los paneles acoplados), aunque tengan WS_CLIPCHILDREN. Por eso
    * el primer acople (por ejemplo en ON INIT) calculaba la
    * geometria bien pero los paneles no se repintaban hasta el
    * primer resize real de la ventana (que FiveWin si propaga a
    * todos sus hijos por su cuenta). RedrawWindow con
    * RDW_ALLCHILDREN si baja el repintado a todo el arbol de
    * ventanas hijas de una.
    */
   RedrawWindow(
      pManager->hMainWnd,
      NULL,
      NULL,
      RDW_INVALIDATE | RDW_ALLCHILDREN | RDW_UPDATENOW | RDW_ERASE );

   return TRUE;
}