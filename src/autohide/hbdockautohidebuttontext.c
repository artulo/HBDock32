#include <windows.h>
#include <tchar.h>

#include "hbdockautohidebuttontext.h"

void hbDockAutoHideButtonSetText(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   LPCTSTR pszText )
{
   if( pButton == NULL )
      return;

   if( pszText == NULL )
      pszText = TEXT( "" );

   _tcsncpy(
      pButton->Text,
      pszText,
      HB_DOCK_AUTOHIDE_TEXT_MAX - 1 );

   pButton->Text[
      HB_DOCK_AUTOHIDE_TEXT_MAX - 1 ] = TEXT( '\0' );
}

int hbDockAutoHideButtonGetText(
   HB_DOCK_AUTOHIDE_BUTTON * pButton,
   LPTSTR pszText,
   int nMax )
{
   if( pButton == NULL ||
       pszText == NULL ||
       nMax <= 0 )
      return 0;

   _tcsncpy(
      pszText,
      pButton->Text,
      nMax - 1 );

   pszText[ nMax - 1 ] = TEXT( '\0' );

   return ( int ) _tcslen( pszText );
}