#include "hbdockdockoperation.h"

#include "hbdockmanagerfindpanel.h"
#include "hbdockpanelstate.h"
#include "hbdocklayoutinsert.h"
#include "hbdocklayoutmutation.h"
#include "hbdockautohideinsert.h"
#include "hbdockautohidepane.h"

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
      &pManager->AutoHideManager,
      0,
      (HB_DOCK_AUTOHIDE_PANE *) pPanel );
}

BOOL hbDockExecuteTab(
      HB_DOCK_MANAGER * pManager,
      const HB_DOCK_COMMAND * pCommand )
{
    return hbDockLayoutTabifyPanel(
      &pManager->LayoutTree,
      (HB_DOCK_PANEL *) pCommand->pSource,
      (HB_DOCK_PANEL *) pCommand->pTarget );
}