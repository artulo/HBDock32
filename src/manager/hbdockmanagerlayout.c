#include <windows.h>

#include "hbdockmanagerlayout.h"

#include "hbdocklayoutrecalc.h"
#include "hbdocklayoutoptimizer.h"
#include "hbdocklayoutremoveempty.h"


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


   InvalidateRect(
      pManager->hMainWnd,
      NULL,
      TRUE );
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