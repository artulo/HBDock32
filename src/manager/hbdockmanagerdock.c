#include <windows.h>
 
#include "hbdockmanagerdock.h"

#include "hbdocklayoutinsertpanel.h"
#include "hbdockcontainer.h"
#include "hbdockmanagertabify.h"

static HB_DOCK_SITE hbDockGuideToSite(
   HB_DOCK_GUIDE_TYPE Guide )
{
   switch( Guide )
   {
      case HB_GUIDE_LEFT:
         return HB_DOCKSITE_LEFT;

      case HB_GUIDE_RIGHT:
         return HB_DOCKSITE_RIGHT;

      case HB_GUIDE_TOP:
         return HB_DOCKSITE_TOP;

      case HB_GUIDE_BOTTOM:
         return HB_DOCKSITE_BOTTOM;

      case HB_GUIDE_CENTER:
         return HB_DOCKSITE_CENTER;

      default:
         return HB_DOCKSITE_NONE;
   }
}

BOOL hbDockManagerDockPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_GUIDE_TYPE Guide )
{
   HB_DOCK_CONTAINER * pContainer;
   HB_DOCK_SITE Site;

   if( pManager == NULL )
      return FALSE;

   if( pPanel == NULL )
      return FALSE;

   Site =
      hbDockGuideToSite(
         Guide );

   if( Site == HB_DOCKSITE_NONE )
      return FALSE;

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

   pContainer->Type =
      HB_CONTAINER_TABS;

   pContainer->TabGroup.pPanel =
      pPanel;
	  
	if( Guide == HB_GUIDE_CENTER )
	{
	   HB_DOCK_LAYOUT_NODE * pNode;

	   pNode =
		  pManager->LayoutTree.Root;

	   if( pNode != NULL )
	   {
		  if( pNode->Type == HB_LAYOUT_LEAF )
		  {
			 return hbDockManagerTabifyPanel(
				pManager,
				pNode->pContainer,
				pPanel );
		  }
	   }
	}
	
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