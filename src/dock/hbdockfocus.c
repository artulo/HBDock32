#include "hbdockfocus.h"

void hbDockFocusInit(
   HB_DOCK_FOCUS * pFocus )
{
   pFocus->Current = NULL;
   pFocus->Previous = NULL;
}

void hbDockFocusSet(
   HB_DOCK_FOCUS * pFocus,
   HB_DOCK_PANEL * pPanel )
{
   pFocus->Previous =
      pFocus->Current;

   pFocus->Current =
      pPanel;
}

HB_DOCK_PANEL * hbDockFocusGet(
   HB_DOCK_FOCUS * pFocus )
{
   return pFocus->Current;
}