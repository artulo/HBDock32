#include <windows.h>

#include "hbdockmanagerrefreshlayout.h"

#include "hbdocklayoutremoveempty.h"
#include "hbdocklayoutoptimizer.h"
#include "hbdocklayoutrecalc.h"


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
    * Recalcular el layout.
    */
   hbDockLayoutRecalc(
      &pManager->LayoutTree,
      &rcClient );


   /*
    * Repintar.
    */
   InvalidateRect(
      pManager->hMainWnd,
      NULL,
      TRUE );

   UpdateWindow(
      pManager->hMainWnd );

   return TRUE;
}