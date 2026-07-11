#include <windows.h>

#include "hbdockautohidecursor.h"

HCURSOR hbDockAutoHideLoadCursor(
   LPCTSTR lpName )
{
   return LoadCursor(
      NULL,
      lpName );
}

void hbDockAutoHideSetCursor(
   HCURSOR hCursor )
{
   SetCursor(
      hCursor );
}