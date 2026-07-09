#include "hbdockfloatingattach.h"

void hbDockFloatingAttachPanel(
   HB_DOCK_FLOATING_FRAME * pFrame,
   HB_DOCK_PANEL * pPanel )
{
   if( pFrame == NULL )
      return;

   pFrame->Panel = pPanel;
}

HB_DOCK_PANEL * hbDockFloatingDetachPanel(
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   HB_DOCK_PANEL * pPanel;

   if( pFrame == NULL )
      return NULL;

   pPanel = pFrame->Panel;
   pFrame->Panel = NULL;

   return pPanel;
}

HB_DOCK_PANEL * hbDockFloatingGetPanel(
   const HB_DOCK_FLOATING_FRAME * pFrame )
{
   if( pFrame == NULL )
      return NULL;

   return pFrame->Panel;
}