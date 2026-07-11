#include <windows.h>

#include "hbdockautohideclass.h"
#include "hbdockautohidecreate.h"

HWND hbDockAutoHideCreate(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   HWND hParent,
   LPCTSTR pszCaption )
{
   if( pPane == NULL )
      return NULL;

   pPane->hWnd =
      CreateWindowEx(
         0,
         HB_DOCK_AUTOHIDE_CLASS,
         pszCaption,
         WS_CHILD |
         WS_CLIPSIBLINGS |
         WS_CLIPCHILDREN,
         0,
         0,
         0,
         0,
         hParent,
         NULL,
         GetModuleHandle( NULL ),
         NULL );

   return pPane->hWnd;
}