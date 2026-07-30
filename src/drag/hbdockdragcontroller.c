#include <windows.h>

#include "hbdockdragcontroller.h"
#include "hbdockguidemanager.h"
#include "hbdockdrag.h"
#include "hbdockmanagerdock.h"
#include "hbdockmanagertabify.h"
#include "hbdockhittest.h"

void hbDockDragControllerInit(
   HB_DOCK_DRAG_CONTROLLER * pController,
   HB_DOCK_MANAGER * pManager )
{
   if( pController == NULL )
      return;

   ZeroMemory(
      pController,
      sizeof( HB_DOCK_DRAG_CONTROLLER ) );

   pController->pManager = pManager;
   pController->pPanel = NULL;

   hbDockDragInit(
      &pController->Drag );
}

/*
 * Etapa 20: recalcula que panel esta debajo de pt (si hay alguno) y
 * reposiciona el diamante centrado sobre EL -- no sobre el mouse.
 * Si no hay ningun panel bajo el cursor, el diamante se oculta (no
 * tiene sentido acoplar "relativo a nada"); las guias externas ya
 * quedaron fijas desde hbDockDragControllerBegin y no se tocan aca.
 */
static void hbDockDragControllerUpdateTarget(
   HB_DOCK_DRAG_CONTROLLER * pController,
   POINT pt )
{
   HB_DOCK_HITTEST Hit;
   HB_DOCK_LAYOUT_NODE * pOldTarget;

   pOldTarget = pController->Drag.TargetNode;

   hbDockHitTestTree(
      pController->pManager->LayoutTree.Root,
      pt,
      &Hit );

   if( Hit.Hit == HB_DOCK_HIT_PANEL && Hit.pNode != NULL &&
       Hit.pNode->pContainer != pController->pPanel->pContainer )
   {
      POINT ptCenter;

      pController->Drag.TargetNode = Hit.pNode;

      ptCenter.x =
         ( Hit.pNode->Rect.left +
           Hit.pNode->Rect.right ) / 2;

      ptCenter.y =
         ( Hit.pNode->Rect.top +
           Hit.pNode->Rect.bottom ) / 2;

      hbDockGuideManagerMoveDiamond(
         &pController->pManager->GuideManager,
         ptCenter );

      if( pOldTarget == NULL )
         hbDockDiamondShow(
            &pController->pManager->GuideManager.Diamond );
   }
   else
   {
      pController->Drag.TargetNode = NULL;

      if( pOldTarget != NULL )
         hbDockDiamondHide(
            &pController->pManager->GuideManager.Diamond );
   }
}

BOOL hbDockDragControllerBegin(
   HB_DOCK_DRAG_CONTROLLER * pController,
   HB_DOCK_PANEL * pPanel,
   HWND hWnd,
   POINT pt )
{
   RECT rcClient;

   if( pController == NULL )
      return FALSE;

   if( pController->pManager == NULL )
      return FALSE;

   if( pPanel == NULL )
      return FALSE;

   pController->pPanel = pPanel;

   hbDockDragBegin(
      &pController->Drag,
      hWnd,
      pt );

   SetCapture(
      hWnd );

   /*
    * Etapa 20: las 4 guias externas se posicionan UNA VEZ, cerca de
    * los bordes de la ventana principal, y quedan fijas durante todo
    * el arrastre (a diferencia del diamante, que sigue al panel bajo
    * el cursor -- ver hbDockDragControllerUpdateTarget).
    */
   GetClientRect(
      hWnd,
      &rcClient );

   hbDockGuideManagerPositionOuter(
      &pController->pManager->GuideManager,
      &rcClient );

   hbDockGuideManagerShow(
      &pController->pManager->GuideManager );

   /* El diamante arranca oculto -- recien se muestra cuando el mouse
    * pasa por encima de un panel real (ver UpdateTarget). */
   hbDockDiamondHide(
      &pController->pManager->GuideManager.Diamond );

   hbDockDragControllerUpdateTarget(
      pController,
      pt );

   return TRUE;
}

void hbDockDragControllerMove(
   HB_DOCK_DRAG_CONTROLLER * pController,
   POINT pt )
{
   if( pController == NULL )
      return;

   if( !pController->Drag.Dragging )
      return;

   hbDockDragUpdate(
      &pController->Drag,
      pt );

   hbDockDragControllerUpdateTarget(
      pController,
      pt );

   pController->Drag.Guide =
      hbDockDragHitTest(
         pController );
}

void hbDockDragControllerEnd(
   HB_DOCK_DRAG_CONTROLLER * pController )
{
   if( pController == NULL )
      return;

   if( !pController->Drag.Dragging )
      return;

   /*
    * Etapa 20 (fix): la decision de a donde acoplar NO va aca -- va
    * en hbDockManagerEndDrag (src/manager/hbdockmanagerdrag.c), que
    * es quien la tenia desde siempre y ya lee Guide/pPanel ANTES de
    * llamar a esta funcion. Ponerla tambien aca causaba un DOBLE
    * acoplado: esta funcion acoplaba una vez (bien, relativo al
    * target), y hbDockManagerEndDrag volvia a acoplar despues (mal,
    * con la logica vieja siempre relativa a toda la ventana) --
    * confirmado con perdida real del panel al probar. Esta funcion
    * vuelve a ser pura limpieza: ocultar guias, soltar captura,
    * terminar el drag. hbDockManagerEndDrag lee TargetNode/GuideSource
    * (via los accesores nuevos) ANTES de llamar aca, para poder
    * elegir entre DockRelative/TabifyPanel (diamante) o DockPanel
    * (guia externa).
    */
   hbDockGuideManagerHide(
      &pController->pManager->GuideManager );

   ReleaseCapture();

   hbDockDragEnd(
      &pController->Drag );

   pController->pPanel = NULL;
}

void hbDockDragControllerCancel(
   HB_DOCK_DRAG_CONTROLLER * pController )
{
   if( pController == NULL )
      return;

   if( !pController->Drag.Dragging )
      return;

   hbDockGuideManagerHide(
      &pController->pManager->GuideManager );

   ReleaseCapture();

   hbDockDragCancel(
      &pController->Drag );

   pController->pPanel = NULL;
}
