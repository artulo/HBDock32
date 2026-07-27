#include "hbdockmanagerdrag.h"

#include "hbdockdragcontroller.h"
#include "hbdockmanagerdock.h"
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


   hbDockManagerDockPanel(
      pManager,
      pPanel,
      Guide );


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