#include <windows.h>

#include "hbdocktabpanel.h"
#include "hbdocktabgroup.h"


void hbDockTabPanelInit(
   HB_DOCK_TAB_PANEL * pPanel,
   HB_DOCK_TAB_GROUP * pGroup )
{
   if( pPanel == NULL )
      return;


   ZeroMemory(
      pPanel,
      sizeof( HB_DOCK_TAB_PANEL ) );


   pPanel->Group =
      pGroup;


   pPanel->HeaderHeight =
      24;
}


void hbDockTabPanelSetRect(
   HB_DOCK_TAB_PANEL * pPanel,
   const RECT * pRect )
{
   if( pPanel == NULL )
      return;


   if( pRect == NULL )
      return;


   pPanel->ClientRect =
      *pRect;


   pPanel->HeaderRect =
      *pRect;


   pPanel->HeaderRect.bottom =
      pPanel->HeaderRect.top +
      pPanel->HeaderHeight;


   pPanel->ClientRect.top =
      pPanel->HeaderRect.bottom;
}


HB_DOCK_PANEL * hbDockTabPanelGetActive(
   HB_DOCK_TAB_PANEL * pPanel )
{
   if( pPanel == NULL )
      return NULL;


   if( pPanel->Group == NULL )
      return NULL;


   return hbDockTabGroupGetActivePanel(
      pPanel->Group );
}