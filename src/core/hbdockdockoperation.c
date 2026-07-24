#include "hbdockdockoperation.h"

#include "hbdockpanel.h"
#include "hbdockpanelstate.h"

#include "hbdocklayoutinsert.h"
#include "hbdocklayoutmutation.h"
#include "hbdocklayouttabify.h"

#include "hbdockautohideinsert.h"
#include "hbdockautohidepane.h"



BOOL hbDockExecuteDock(
   HB_DOCK_MANAGER * pManager,
   const HB_DOCK_COMMAND * pCommand )
{
   HB_DOCK_PANEL * pPanel;
   LPARAM lSide;

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

   lSide = pCommand->Param;

   return hbDockLayoutInsertPanel(
      &pManager->LayoutTree,
      pPanel,
      ( int ) lSide );
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