#include <string.h>

#include "hbdockpanelhint.h"

void hbDockPanelSetHint(
   HB_DOCK_PANEL * pPanel,
   const char * pszHint )
{
   if( pPanel == NULL )
      return;

   if( pszHint == NULL )
      pszHint = "";

   strncpy(
      pPanel->Hint,
      pszHint,
      sizeof( pPanel->Hint ) - 1 );

   pPanel->Hint[
      sizeof( pPanel->Hint ) - 1 ] = '\0';
}

const char * hbDockPanelGetHint(
   const HB_DOCK_PANEL * pPanel )
{
   if( pPanel == NULL )
      return "";

   return pPanel->Hint;
}