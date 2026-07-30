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
      &rcClient );

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
      pRect );


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