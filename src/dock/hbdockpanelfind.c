#include <string.h>

#include "hbdockpanelfind.h"

HB_DOCK_PANEL * hbDockPanelFindById(
   HB_DOCK_NODE * pRoot,
   unsigned int Id )
{
   HB_DOCK_PANEL * pPanel;

   if( pRoot == NULL )
      return NULL;

   if( pRoot->Type == HB_DOCK_NODE_LEAF )
   {
      pPanel = pRoot->Panel;

      if( pPanel != NULL &&
          pPanel->Id == Id )
         return pPanel;

      return NULL;
   }

   pPanel =
      hbDockPanelFindById(
         pRoot->First,
         Id );

   if( pPanel != NULL )
      return pPanel;

   return hbDockPanelFindById(
      pRoot->Second,
      Id );
}

HB_DOCK_PANEL * hbDockPanelFindByName(
   HB_DOCK_NODE * pRoot,
   const char * pszName )
{
   HB_DOCK_PANEL * pPanel;

   if( pRoot == NULL )
      return NULL;

   if( pRoot->Type == HB_DOCK_NODE_LEAF )
   {
      pPanel = pRoot->Panel;

      if( pPanel != NULL &&
          strcmp(
             pPanel->Name,
             pszName ) == 0 )
         return pPanel;

      return NULL;
   }

   pPanel =
      hbDockPanelFindByName(
         pRoot->First,
         pszName );

   if( pPanel != NULL )
      return pPanel;

   return hbDockPanelFindByName(
      pRoot->Second,
      pszName );
}