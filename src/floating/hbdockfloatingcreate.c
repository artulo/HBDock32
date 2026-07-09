#include <windows.h>

#include "hbdockfloatingclass.h"
#include "hbdockfloatingcreate.h"

HWND hbDockFloatingCreateWindow(
   HB_DOCK_FLOATING_FRAME * pFrame,
   HWND hOwner,
   LPCTSTR lpCaption )
{
   if( pFrame == NULL )
      return NULL;

   pFrame->hWnd =
      CreateWindowEx(
         pFrame->ExStyle,
         HB_DOCK_FLOATING_CLASS,
         lpCaption,
         pFrame->Style,
         pFrame->Rect.left,
         pFrame->Rect.top,
         pFrame->Rect.right -
            pFrame->Rect.left,
         pFrame->Rect.bottom -
            pFrame->Rect.top,
         hOwner,
         NULL,
         GetModuleHandle( NULL ),
         pFrame );

   return pFrame->hWnd;
}