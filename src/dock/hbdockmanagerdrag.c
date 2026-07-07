#include "hbdockmanagerdrag.h"
#include "hbdockmanagerdock.h"
#include "hbdockmanagerlayout.h"
#include "hbdockmanagerfloat.h"
#include "hbdockhittest.h"
#include "hbdockpaneldock.h"
#include "hbdockpanelfloating.h"

void hbDockManagerBeginDrag(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   POINT pt )
{
   if( pManager == NULL || pPanel == NULL )
      return;

   /* Guarda el sitio original por si el arrastre se cancela */
   pPanel->Tag = ( long ) hbDockPanelGetDockSite( pPanel );

   hbDockManagerUndockPanel(
      pManager,
      pPanel );

   pPanel->Visible = 0;

   hbDockManagerLayout(
      pManager );

   hbDockDragTrackerBegin(
      &pManager->DragTracker,
      pPanel,
      pt );
}

int hbDockManagerDragMove(
   HB_DOCK_MANAGER * pManager,
   POINT pt )
{
   if( pManager == NULL )
      return 0;

   if( !pManager->DragTracker.Context.Dragging )
      return 0;

   hbDockDragTrackerMove(
      &pManager->DragTracker,
      pManager->LayoutEngine.Root,
      pt );

   return 1;
}

void hbDockManagerEndDrag(
   HB_DOCK_MANAGER * pManager,
   POINT pt )
{
   HB_DOCK_PANEL * pPanel;
   HB_DOCK_SITE Site;
   HB_DOCK_HITTEST Hit;
   HB_DOCK_NODE * pTargetNode;

   if( pManager == NULL )
      return;

   if( !pManager->DragTracker.Context.Dragging )
      return;

   pPanel = pManager->DragTracker.Context.DragPanel;
   Site   = pManager->DragTracker.Context.CurrentSite;

   hbDockDragTrackerEnd(
      &pManager->DragTracker );

   if( pPanel == NULL )
      return;

   if( Site == HB_DOCKSITE_NONE )
   {
      /* Se solto fuera de cualquier guia: pasa a flotante */
      hbDockManagerFloatPanel(
         pManager,
         pPanel,
         pt );

      return;
   }

   /* Ubica el nodo bajo el cursor dentro de lo que queda
    * del arbol para acoplar el panel junto a el. */
   hbDockHitTestTree(
      pManager->LayoutEngine.Root,
      pt,
      &Hit );

   pTargetNode = Hit.Node;

   pPanel->Visible = 1;
   pPanel->Floating = 0;

   hbDockManagerDockPanelAt(
      pManager,
      pTargetNode,
      pPanel,
      Site );

   hbDockManagerLayout(
      pManager );
}

void hbDockManagerCancelDrag(
   HB_DOCK_MANAGER * pManager )
{
   HB_DOCK_PANEL * pPanel;
   HB_DOCK_SITE Site;

   if( pManager == NULL )
      return;

   if( !pManager->DragTracker.Context.Dragging )
      return;

   pPanel = pManager->DragTracker.Context.DragPanel;

   hbDockDragTrackerEnd(
      &pManager->DragTracker );

   if( pPanel == NULL )
      return;

   /* Restauracion aproximada: se reacopla al mismo lado
    * que tenia antes del arrastre, contra la raiz actual
    * del arbol (no se conserva la posicion exacta dentro
    * del arbol, solo el lado). */
   Site = ( HB_DOCK_SITE ) pPanel->Tag;

   pPanel->Visible = 1;

   hbDockManagerDockPanelAt(
      pManager,
      pManager->LayoutEngine.Root,
      pPanel,
      Site );

   hbDockManagerLayout(
      pManager );
}
