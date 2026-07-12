#include <windows.h>

#include "hbdocktargetapply.h"

BOOL hbDockApplyResolvedTarget(
      HB_DOCK_TARGET_INFO * pInfo,
      HWND hDockWindow )
{
   RECT * rc;

   if( pInfo == NULL )
      return FALSE;

   rc = &pInfo->PreviewRect;

   MoveWindow(
      hDockWindow,
      rc->left,
      rc->top,
      rc->right - rc->left,
      rc->bottom - rc->top,
      TRUE );

   return TRUE;
}