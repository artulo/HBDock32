#include <string.h>

#include "hbdockpaneltext.h"

void hbDockPanelSetCaption(
   HB_DOCK_PANEL * pPanel,
   const char * pszText )
{
   if( pPanel == NULL )
      return;

   if( pszText == NULL )
      pszText = "";

   strncpy(
      pPanel->Caption,
      pszText,
      sizeof( pPanel->Caption ) - 1 );

   pPanel->Caption[
      sizeof( pPanel->Caption ) - 1 ] = 0;
}

const char * hbDockPanelGetCaption(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return "";

   return pPanel->Caption;
}