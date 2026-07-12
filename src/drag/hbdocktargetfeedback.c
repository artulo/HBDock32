#include "hbdocktargetfeedback.h"

void hbDockTargetSetActive(
      HB_DOCK_TARGET_INFO * pInfo )
{
   if( pInfo )
      pInfo->hTarget =
         GetActiveWindow();
}

void hbDockTargetClear(
      HB_DOCK_TARGET_INFO * pInfo )
{
   if( pInfo )
      pInfo->Target =
         HB_DOCK_TARGET_NONE;
}