#include <windows.h>

#include "hbdockguidecreate.h"

BOOL hbDockGuideCreate(
   HB_DOCK_GUIDE * pGuide,
   HWND hParent,
   HB_DOCK_GUIDE_TYPE Type )
{
   if( pGuide == NULL )
      return FALSE;

   ZeroMemory(
      pGuide,
      sizeof( HB_DOCK_GUIDE ) );

   pGuide->Type = Type;
   pGuide->Visible = FALSE;
   pGuide->Enabled = TRUE;

   pGuide->hWnd = CreateWindowEx(
      WS_EX_TOOLWINDOW,
      TEXT( "STATIC" ),
      TEXT( "" ),
      WS_POPUP,
      0,
      0,
      32,
      32,
      hParent,
      NULL,
      GetModuleHandle( NULL ),
      NULL );

   return pGuide->hWnd != NULL;
}

void hbDockGuideDestroy(
   HB_DOCK_GUIDE * pGuide )
{
   if( pGuide == NULL )
      return;

   if( pGuide->hWnd )
   {
      DestroyWindow(
         pGuide->hWnd );

      pGuide->hWnd = NULL;
   }
}