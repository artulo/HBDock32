#include <string.h>

#include "hbdockpanelname.h"

void hbDockPanelSetName(
   HB_DOCK_PANEL * pPanel,
   const char * pszName )
{
   if( pPanel == NULL )
      return;

   if( pszName == NULL )
      pszName = "";

   strncpy(
      pPanel->Name,
      pszName,
      sizeof( pPanel->Name ) - 1 );

   pPanel->Name[
      sizeof( pPanel->Name ) - 1 ] = 0;
}

const char * hbDockPanelGetName(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return "";

   return pPanel->Name;
}