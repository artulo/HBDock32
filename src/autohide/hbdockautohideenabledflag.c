#include "hbdockautohideenabledflag.h"

void hbDockAutoHideSetEnabledFlag(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int bEnabled )
{
   if( pPane != NULL )
      pPane->Enabled = bEnabled;
}

int hbDockAutoHideGetEnabledFlag(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->Enabled;
}