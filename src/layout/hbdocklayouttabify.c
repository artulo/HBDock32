#include <windows.h>
#include <stdlib.h>

#include "hbdocklayouttabify.h"
#include "hbdockcontainer.h"


static HB_DOCK_LAYOUT_NODE * hbDockLayoutFindPanelNode(
   HB_DOCK_LAYOUT_NODE * pNode,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_LAYOUT_NODE * pFound;


   if( pNode == NULL )
      return NULL;


   if( pNode->Type == HB_LAYOUT_LEAF )
   {
      if( pNode->pContainer != NULL )
      {
         if( pNode->pContainer->TabGroup.pPanel == pPanel )
            return pNode;
      }

      return NULL;
   }


   pFound =
      hbDockLayoutFindPanelNode(
         pNode->First,
         pPanel );


   if( pFound != NULL )
      return pFound;


   return hbDockLayoutFindPanelNode(
      pNode->Second,
      pPanel );
}



static BOOL hbDockLayoutAddTab(
   HB_DOCK_CONTAINER * pContainer,
   HB_DOCK_PANEL * pPanel )
{
   if( pContainer == NULL )
      return FALSE;


   if( pPanel == NULL )
      return FALSE;


   /*
    * La estructura TabGroup será la responsable
    * de mantener la lista de pestañas.
    */

   return hbDockContainerAddTab(
      pContainer,
      pPanel );
}



BOOL hbDockLayoutTabifyPanel(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_PANEL * pSource,
   HB_DOCK_PANEL * pTarget )
{
   HB_DOCK_LAYOUT_NODE * pTargetNode;


   if( pTree == NULL )
      return FALSE;


   if( pTree->Root == NULL )
      return FALSE;


   if( pSource == NULL ||
       pTarget == NULL )
      return FALSE;



   pTargetNode =
      hbDockLayoutFindPanelNode(
         pTree->Root,
         pTarget );


   if( pTargetNode == NULL )
      return FALSE;



   if( pTargetNode->Type != HB_LAYOUT_LEAF )
      return FALSE;



   if( pTargetNode->pContainer == NULL )
      return FALSE;



   return hbDockLayoutAddTab(
      pTargetNode->pContainer,
      pSource );
}