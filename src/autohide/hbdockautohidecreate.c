#include <windows.h>

#include "hbdockautohideclass.h"
#include "hbdockautohidecreate.h"


HWND hbDockAutoHideCreate(
   HB_DOCK_AUTOHIDE * pAutoHide,
   HWND hParent,
   LPCTSTR pszCaption )
{
   HWND hWnd;

   if( pAutoHide == NULL )
      return NULL;

   hWnd =
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

   if( hWnd == NULL )
      return NULL;

   if( pAutoHide->Panel != NULL )
   {
      pAutoHide->Panel->hWnd = hWnd;
   }

   return hWnd;
}