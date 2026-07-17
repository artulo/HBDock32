#include <windows.h>

#include "hbdockautohidebuttonuserdata.h"

void hbDockAutoHideButtonSetUserData(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   void * pData )
{
   if( pButton == NULL )
      return;

   pButton->pUserData = pData;
}

void * hbDockAutoHideButtonGetUserData(
   HB_DOCK_AUTOHIDE_BUTTON * pButton )
{
   if( pButton == NULL )
      return NULL;

   return pButton->pUserData;
}