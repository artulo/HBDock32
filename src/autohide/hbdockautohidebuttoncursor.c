#include <windows.h>

#include "hbdockautohidebuttoncursor.h"

HCURSOR hbDockAutoHideButtonLoadCursor(
   LPCTSTR lpName )
{
   return LoadCursor(
      NULL,
      lpName );
}

void hbDockAutoHideButtonSetCursor(
   HCURSOR hCursor )
{
   SetCursor(
      hCursor );
}