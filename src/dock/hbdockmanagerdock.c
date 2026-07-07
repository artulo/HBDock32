#include "hbdockmanagerdock.h"

#include "hbdockdockoperation.h"
#include "hbdocktreefind.h"
#include "hbdocktreeremove.h"
#include "hbdockpaneldock.h"

HB_DOCK_NODE * hbDockManagerDockPanelAt(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_NODE * pTargetNode,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_SITE Site )
{
   HB_DOCK_NODE * pParent;
   HB_DOCK_NODE * pSplit;

   if( pManager == NULL || pPanel == NULL )
      return NULL;

   if( pTargetNode == NULL || pManager->LayoutEngine.Root == NULL )
   {
      HB_DOCK_NODE * pLeaf = hbDockNodeNewLeaf( pPanel );

      pManager->LayoutEngine.Root = pLeaf;

      hbDockPanelSetDockSite(
         pPanel,
         Site == HB_DOCKSITE_NONE ? HB_DOCKSITE_CENTER : Site );

      return pLeaf;
   }

   pParent = pTargetNode->Parent;

   pSplit = hbDockInsertPanel(
      pTargetNode,
      pPanel,
      Site );

   if( pSplit == NULL || pSplit == pTargetNode )
      return pSplit;

   pSplit->Parent = pParent;

   if( pParent == NULL )
      pManager->LayoutEngine.Root = pSplit;
   else if( pParent->First == pTargetNode )
      pParent->First = pSplit;
   else
      pParent->Second = pSplit;

   hbDockPanelSetDockSite(
      pPanel,
      Site );

   return pSplit;
}

int hbDockManagerUndockPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_NODE * pLeaf;

   if( pManager == NULL || pPanel == NULL )
      return 0;

   pLeaf = hbDockTreeFindPanel(
      pManager->LayoutEngine.Root,
      pPanel );

   if( pLeaf == NULL )
      return 0;

   pManager->LayoutEngine.Root = hbDockTreeRemoveNode(
      pManager->LayoutEngine.Root,
      pLeaf );

   return 1;
}
