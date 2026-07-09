#include <windows.h>

#include "hbdockfloatingcursor.h"

HCURSOR hbDockFloatingLoadCursor(
   LPCTSTR pszCursor )
{
   return LoadCursor(
      NULL,
      pszCursor );
}

void hbDockFloatingSetCursor(
   HCURSOR hCursor )
{
   SetCursor(
      hCursor );
}