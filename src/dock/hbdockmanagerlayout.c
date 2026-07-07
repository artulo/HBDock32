#include <windows.h>

#include "hbdockmanagerlayout.h"

void hbDockManagerLayout(
   HB_DOCK_MANAGER * pManager )
{
   HB_DOCK_PANEL * p;

   if( pManager == NULL )
      return;

   if( pManager->hWnd != NULL )
      GetClientRect(
         pManager->hWnd,
         &pManager->ClientRect );

   /* 1) Calcula los rects de cada panel recorriendo
    *    el arbol de docking (splits / leaves).
    */
   hbDockLayoutEnginePerform(
      &pManager->LayoutEngine,
      &pManager->ClientRect );

   /* 2) Aplica esos rects a las ventanas reales
    *    de cada panel registrado en el manager.
    */
   p = pManager->FirstPanel;

   while( p != NULL )
   {
      if( p->Visible && !p->Floating && p->hWnd != NULL )
      {
         MoveWindow(
            p->hWnd,
            p->Rect.left,
            p->Rect.top,
            p->Rect.right  - p->Rect.left,
            p->Rect.bottom - p->Rect.top,
            TRUE );
      }

      p = p->Next;
   }
}

void hbDockManagerResize(
   HB_DOCK_MANAGER * pManager,
   int cx,
   int cy )
{
   if( pManager == NULL )
      return;

   SetRect(
      &pManager->ClientRect,
      0,
      0,
      cx,
      cy );

   hbDockManagerLayout(
      pManager );
}