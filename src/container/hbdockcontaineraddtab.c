#include <windows.h>

#include "hbdockcontaineraddtab.h"
#include "hbdocktabgroup.h"


BOOL hbDockContainerAddTab(
   HB_DOCK_CONTAINER * pContainer,
   HB_DOCK_PANEL * pPanel )
{
   if( pContainer == NULL )
      return FALSE;

   if( pPanel == NULL )
      return FALSE;


   return hbDockTabGroupAddPanel(
      &pContainer->TabGroup,
      pPanel );
}



BOOL hbDockContainerRemoveTab(
   HB_DOCK_CONTAINER * pContainer,
   HB_DOCK_PANEL * pPanel )
{
   if( pContainer == NULL )
      return FALSE;

   if( pPanel == NULL )
      return FALSE;


   return hbDockTabGroupRemovePanel(
      &pContainer->TabGroup,
      pPanel );
}