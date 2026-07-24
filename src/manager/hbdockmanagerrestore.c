#include <windows.h>

#include "hbdockmanagerrestore.h"

#include "hbdockmanagerdock.h"
#include "hbdockfloating.h"

static HB_DOCK_GUIDE_TYPE hbDockRestoreGuideFromSite(
   HB_DOCK_SITE Site )
{
   switch( Site )
   {
      case HB_DOCKSITE_LEFT:
         return HB_GUIDE_LEFT;

      case HB_DOCKSITE_RIGHT:
         return HB_GUIDE_RIGHT;

      case HB_DOCKSITE_TOP:
         return HB_GUIDE_TOP;

      case HB_DOCKSITE_BOTTOM:
         return HB_GUIDE_BOTTOM;

      default:
         return HB_GUIDE_CENTER;
   }
}


BOOL hbDockManagerRestore(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_LAYOUT_NODE * pTarget,
   HB_DOCK_CONTAINER * pContainer,
   HB_DOCK_SITE Site )
{
   HB_DOCK_PANEL * pPanel;
   HB_DOCK_GUIDE_TYPE Guide;

(void) pTarget;

   if( pManager == NULL )
      return FALSE;


   if( pContainer == NULL )
      return FALSE;


   pPanel =
      pContainer->TabGroup.pPanel;


   if( pPanel == NULL )
      return FALSE;


   if( pPanel->pFloating != NULL )
   {
      hbDockFloatingShow(
         pPanel->pFloating,
         SW_HIDE );
   }


   Guide =
      hbDockRestoreGuideFromSite(
         Site );


   if( !hbDockManagerDockPanel(
          pManager,
          pPanel,
          Guide ) )
   {
      return FALSE;
   }


   pPanel->Floating = FALSE;


   return TRUE;
}