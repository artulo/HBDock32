#include "hbdockdockoperation.h"

#include "hbdockpanel.h"
#include "hbdockpanelstate.h"

#include "hbdocklayoutinsertpanel.h"
#include "hbdocklayoutmutation.h"
#include "hbdocklayouttabify.h"
#include "hbdockcontainer.h"

#include "hbdockautohideinsert.h"
#include "hbdockautohidepane.h"



BOOL hbDockExecuteDock(
   HB_DOCK_MANAGER * pManager,
   const HB_DOCK_COMMAND * pCommand )
{
   HB_DOCK_PANEL * pPanel;
   HB_DOCK_CONTAINER * pContainer;
   HB_DOCK_SITE Site;

   if( pManager == NULL )
      return FALSE;

   if( pCommand == NULL )
      return FALSE;

   pPanel = pCommand->pSource;

   if( pPanel == NULL )
      return FALSE;
  
   hbDockPanelSetState(
      pPanel,
      HB_PANEL_STATE_DOCKED );

   Site = ( HB_DOCK_SITE ) pCommand->Param;

   /* Envuelve el panel suelto en un contenedor nuevo, igual que
    * hbDockManagerDockPanel en src/manager/hbdockmanagerdock.c,
    * para poder usar la firma canonica de hbDockLayoutInsertPanel
    * (arbol, nodo destino, contenedor, sitio). Antes esta funcion
    * llamaba a una version de 3 argumentos (arbol, panel, sitio)
    * que vivia en hbdocklayoutinsert.c y que colisionaba por nombre
    * con esta (Etapa 1, hallazgo de hbDockLayoutInsertPanel). */

   pContainer =
      ( HB_DOCK_CONTAINER * )
      LocalAlloc(
         LPTR,
         sizeof( HB_DOCK_CONTAINER ) );

   if( pContainer == NULL )
      return FALSE;

   if( !hbDockContainerCreate(
            pContainer,
            pManager->hMainWnd ) )
   {
      LocalFree(
         pContainer );

      return FALSE;
   }

   pContainer->Type = HB_CONTAINER_TABS;
   pContainer->TabGroup.pPanel = pPanel;

   if( !hbDockLayoutInsertPanel(
            &pManager->LayoutTree,
            pManager->LayoutTree.Root,
            pContainer,
            Site ) )
   {
      hbDockContainerDestroy(
         pContainer );

      LocalFree(
         pContainer );

      return FALSE;
   }

   return TRUE;
}

BOOL hbDockExecuteAutoHide(
   HB_DOCK_MANAGER * pManager,
   const HB_DOCK_COMMAND * pCommand )
{
   HB_DOCK_PANEL * pPanel;
   HB_DOCK_AUTOHIDE_PANE * pPane;


   if( pManager == NULL )
      return FALSE;


   if( pCommand == NULL )
      return FALSE;


   pPanel =
      pCommand->pSource;


   if( pPanel == NULL )
      return FALSE;


   hbDockPanelSetState(
      pPanel,
      HB_PANEL_STATE_AUTOHIDE );


   pPane =
      (HB_DOCK_AUTOHIDE_PANE *)
      LocalAlloc(
         LPTR,
         sizeof( HB_DOCK_AUTOHIDE_PANE ) );


   if( pPane == NULL )
      return FALSE;


   pPane->pPanel =
      pPanel;


   pPane->Side =
      (int) pCommand->Param;


   pPane->Visible =
      FALSE;


   SetRectEmpty(
      &pPane->Rect );


   if( !hbDockAutoHideInsert(
            &pManager->AutoHideManager,
            0,
            pPane ) )
   {
      LocalFree(
         pPane );

      return FALSE;
   }


   return TRUE;
}




BOOL hbDockExecuteTab(
   HB_DOCK_MANAGER * pManager,
   const HB_DOCK_COMMAND * pCommand )
{
   HB_DOCK_PANEL * pSource;
   HB_DOCK_PANEL * pTarget;


   if( pManager == NULL )
      return FALSE;


   if( pCommand == NULL )
      return FALSE;


   pSource =
      pCommand->pSource;


   pTarget =
      pCommand->pTarget;


   if( pSource == NULL )
      return FALSE;


   if( pTarget == NULL )
      return FALSE;


   return hbDockLayoutTabifyPanel(
      &pManager->LayoutTree,
      pSource,
      pTarget );
}