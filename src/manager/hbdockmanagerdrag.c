#include "hbdockmanagerdrag.h"

#include "hbdockdragcontroller.h"
#include "hbdockmanagerdock.h"
#include "hbdockmanagertabify.h"
#include "hbdockmanagerlayout.h"
#include "hbdockmanagerfloat.h"
#include "hbdockdragpreview.h"

/* Nota de estabilizacion (Etapa 4): esta funcion estaba comentada por
 * completo. include/hbdockmanagerdrag.h la declara y
 * src/host/hbdockhost.c la llama de verdad (WM_LBUTTONDOWN, inicio de
 * arrastre) -- sin el cuerpo, el enlazador iba a fallar con
 * "unresolved external '_hbDockManagerBeginDrag'" apenas se intentara
 * generar el .exe. Se restaura tal cual estaba escrita (coincide con
 * el patron de EndDrag/CancelDrag mas abajo, y pDragController ya se
 * reserva e inicializa en hbdockmanager.c). */
void hbDockManagerBeginDrag(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   POINT pt )
{
   if( pManager == NULL )
      return;

   if( pPanel == NULL )
      return;


   pPanel->Visible = FALSE;


   hbDockDragControllerBegin(
      pManager->pDragController,
      pPanel,
      pManager->hMainWnd,
      pt );


   pManager->Dragging = TRUE;
}


int hbDockManagerDragMove(
   HB_DOCK_MANAGER * pManager,
   POINT pt )
{
   if( pManager == NULL )
      return FALSE;


   if( !hbDockDragIsDragging(
          pManager->pDragController ) )
      return FALSE;


   hbDockDragControllerMove(
      pManager->pDragController,
      pt );


   /* Nota de estabilizacion (Etapa 4): hbDockDragPreviewUpdate ya
    * existia, completa y correcta, pero nada la llamaba -- el overlay
    * de vista previa (creado/destruido en hbdockmanager.c) nunca se
    * mostraba durante el arrastre. Se conecta aqui. */
   hbDockDragPreviewUpdate(
      pManager,
      pt );


   return TRUE;
}



void hbDockManagerEndDrag(
   HB_DOCK_MANAGER * pManager,
   POINT pt )
{
   HB_DOCK_PANEL * pPanel;
   HB_DOCK_GUIDE_TYPE Guide;
   HB_DOCK_GUIDE_SOURCE GuideSource;
   HB_DOCK_LAYOUT_NODE * pTargetNode;


   if( pManager == NULL )
      return;


   if( !hbDockDragIsDragging(
          pManager->pDragController ) )
      return;


   pPanel =
      hbDockDragGetPanel(
         pManager->pDragController );


   Guide =
      hbDockDragHitTest(
         pManager->pDragController );

   /*
    * Etapa 20: hay que leer esto ANTES de hbDockDragControllerEnd --
    * esa funcion llama a hbDockDragEnd, que resetea TargetNode a
    * NULL y GuideSource a NONE como parte de la limpieza normal del
    * drag.
    */
   GuideSource =
      hbDockDragGetGuideSource(
         pManager->pDragController );

   pTargetNode =
      hbDockDragGetTargetNode(
         pManager->pDragController );


   hbDockDragControllerEnd(
      pManager->pDragController );


   hbDockDragPreviewHide(
      pManager );


   pManager->Dragging = FALSE;


   if( pPanel == NULL )
      return;


   pPanel->Visible = TRUE;


   if( Guide == HB_GUIDE_NONE )
   {
      hbDockManagerFloatPanel(
         pManager,
         pPanel,
         pt );

      return;
   }


   /*
    * Etapa 20: hit del DIAMANTE (relativo a un panel puntual) versus
    * hit de una guia EXTERNA (relativo a toda la ventana principal).
    * CENTER tabifica sobre el panel destino real bajo el mouse (no
    * sobre el primer leaf del arbol, que es lo que hace
    * hbDockManagerDockPanel para CENTER cuando no hay un target
    * especifico).
    */
   if( GuideSource == HB_DOCK_GUIDE_SOURCE_DIAMOND &&
       pTargetNode != NULL &&
       pTargetNode->pContainer != NULL )
   {
      if( Guide == HB_GUIDE_CENTER )
      {
         hbDockManagerTabifyPanel(
            pManager,
            pTargetNode->pContainer,
            pPanel );
      }
      else
      {
         hbDockManagerDockRelative(
            pManager,
            pPanel,
            pTargetNode,
            Guide );
      }
   }
   else
   {
      hbDockManagerDockPanel(
         pManager,
         pPanel,
         Guide );
   }


   hbDockManagerLayout(
      pManager );
}



void hbDockManagerCancelDrag(
   HB_DOCK_MANAGER * pManager )
{
   HB_DOCK_PANEL * pPanel;


   if( pManager == NULL )
      return;


   pPanel =
      hbDockDragGetPanel(
         pManager->pDragController );


   hbDockDragControllerCancel(
      pManager->pDragController );


   hbDockDragPreviewHide(
      pManager );


   pManager->Dragging = FALSE;


   if( pPanel != NULL )
      pPanel->Visible = TRUE;
}