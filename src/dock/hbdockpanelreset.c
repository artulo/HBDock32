#include <string.h>

#include "hbdockpanelreset.h"

void hbDockPanelReset(
   HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return;

   memset(
      pPanel,
      0,
      sizeof( HB_DOCK_PANEL ) );
}