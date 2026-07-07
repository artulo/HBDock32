#include "hbdockpanelvalidate.h"

int hbDockPanelIsValid(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return 0;

   if( pPanel->Id == 0 )
      return 0;

   if( pPanel->Name[ 0 ] == '\0' )
      return 0;

   return 1;
}