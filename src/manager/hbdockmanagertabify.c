#include <windows.h>

#include "hbdockmanagertabify.h"
#include "hbdockcontainer.h"
#include "hbdocktabgroup.h"

BOOL hbDockManagerTabifyPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_CONTAINER * pContainer,
   HB_DOCK_PANEL * pPanel )
{
   if( pManager == NULL )
      return FALSE;

   if( pContainer == NULL )
      return FALSE;

   if( pPanel == NULL )
      return FALSE;

   if( pContainer->Type != HB_CONTAINER_TABS )
      return FALSE;

   if( !hbDockTabGroupAddPanel(
            &pContainer->TabGroup,
            pPanel ) )
      return FALSE;

   hbDockTabGroupSetActive(
      &pContainer->TabGroup,
      pContainer->TabGroup.Count - 1 );

   return TRUE;
}