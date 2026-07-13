#include "hbdockdockoperation.h"

#include "hbdockmanagerfindpanel.h"
#include "hbdockpanelstate.h"
#include "hbdocklayoutinsert.h"

BOOL hbDockExecuteDock(
      HB_DOCK_MANAGER * pManager,
      const HB_DOCK_COMMAND * pCommand )
{
   HB_DOCK_PANEL * pPanel;

   pPanel = (HB_DOCK_PANEL *) pCommand->pSource;

   if( pPanel == NULL )
      return FALSE;

   hbDockPanelSetState(
      pPanel,
      HB_PANEL_STATE_DOCKED );

   return hbDockLayoutInsertPanel(
      &pManager->LayoutTree,
      pPanel,
      pCommand->Param );
}

BOOL hbDockExecuteAutoHide(
      HB_DOCK_MANAGER * pManager,
      const HB_DOCK_COMMAND * pCommand )
{
   HB_DOCK_PANEL * pPanel;

   pPanel =
      (HB_DOCK_PANEL *) pCommand->pSource;

   if( pPanel == NULL )
      return FALSE;

   hbDockPanelSetState(
      pPanel,
      HB_PANEL_STATE_AUTOHIDE );

   return hbDockAutoHideInsert(
      pManager,
      pPanel );
}

BOOL hbDockExecuteTab(
      HB_DOCK_MANAGER * pManager,
      const HB_DOCK_COMMAND * pCommand )
{
   return hbDockContainerTabify(
      pCommand->pSource,
      pCommand->pTarget );
}