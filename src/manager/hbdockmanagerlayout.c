#include <windows.h>

#include "hbdockmanagerlayout.h"

#include "hbdocklayoutrecalc.h"
#include "hbdocklayoutoptimizer.h"
#include "hbdocklayoutremoveempty.h"
#include "hbdockmanagerautohide.h"


BOOL hbDockManagerLayout(
   HB_DOCK_MANAGER * pManager )
{
   RECT rcClient;


   if( pManager == NULL )
      return FALSE;

   if( pManager->hMainWnd == NULL )
      return FALSE;


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
    * Etapa 65: reservar margen para la tira de pestañas de AutoHide
    * en los lados que tengan al menos un panel autohidden -- sin
    * esto, un panel acoplado normal podia terminar ocupando el
    * mismo borde donde se pinta la pestaña, tapandola por completo.
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
    * Recalcular geometría.
    */
   hbDockLayoutRecalc(
      &pManager->LayoutTree,
      &rcClient,
      ( void * ) pManager );

   /*
    * Etapa 55: sin esto, las pestañas de AutoHide quedaban
    * "flotando" en las posiciones calculadas antes del resize --
    * nunca se actualizaban con las nuevas dimensiones de la
    * ventana.
    */
   hbDockManagerAutoHideRefreshRects(
      pManager );

   return TRUE;
}



BOOL hbDockManagerLayoutRect(
   HB_DOCK_MANAGER * pManager,
   const RECT * pRect )
{
   if( pManager == NULL )
      return FALSE;

   if( pRect == NULL )
      return FALSE;


   hbDockLayoutRemoveEmpty(
      &pManager->LayoutTree,
      pManager->LayoutTree.Root );


   hbDockLayoutOptimize(
      &pManager->LayoutTree );


   hbDockLayoutRecalc(
      &pManager->LayoutTree,
      pRect,
      ( void * ) pManager );


   return TRUE;
}



void hbDockManagerInvalidateLayout(
   HB_DOCK_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   if( pManager->hMainWnd == NULL )
      return;

   /* Nota de estabilizacion: ver hbdockmanagerrefreshlayout.c --
    * InvalidateRect no baja a las ventanas hijas (los paneles). */
   RedrawWindow(
      pManager->hMainWnd,
      NULL,
      NULL,
      RDW_INVALIDATE | RDW_ALLCHILDREN | RDW_UPDATENOW | RDW_ERASE );
}



void hbDockManagerUpdateLayout(
   HB_DOCK_MANAGER * pManager )
{
   if( pManager == NULL )
      return;


   hbDockManagerLayout(
      pManager );


   hbDockManagerInvalidateLayout(
      pManager );


   UpdateWindow(
      pManager->hMainWnd );
}