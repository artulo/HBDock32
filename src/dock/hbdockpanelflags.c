#include "hbdockpanelflags.h"

void hbDockPanelSetFlags(
   HB_DOCK_PANEL * pPanel,
   unsigned long Flags )
{
   if( pPanel == NULL )
      return;

   pPanel->Flags = Flags;
}

void hbDockPanelAddFlags(
   HB_DOCK_PANEL * pPanel,
   unsigned long Flags )
{
   if( pPanel == NULL )
      return;

   pPanel->Flags |= Flags;
}

void hbDockPanelRemoveFlags(
   HB_DOCK_PANEL * pPanel,
   unsigned long Flags )
{
   if( pPanel == NULL )
      return;

   pPanel->Flags &= ~Flags;
}

int hbDockPanelHasFlags(
   const HB_DOCK_PANEL * pPanel,
   unsigned long Flags )
{
   if( pPanel == NULL )
      return 0;

   return ( pPanel->Flags & Flags ) == Flags;
}