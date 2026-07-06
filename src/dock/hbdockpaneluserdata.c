#include "hbdockpaneluserdata.h"

void hbDockPanelSetUserData(
   HB_DOCK_PANEL * pPanel,
   void * pData )
{
   if( pPanel == NULL )
      return;

   pPanel->UserData = pData;
}

void * hbDockPanelGetUserData(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return NULL;

   return pPanel->UserData;
}