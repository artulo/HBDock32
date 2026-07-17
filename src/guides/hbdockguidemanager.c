#include <windows.h>

#include "hbdockguidemanager.h"
#include "hbdockguidecreate.h"
#include "hbdockguidepaint.h"

BOOL hbDockGuideManagerInit(
   HB_DOCK_GUIDE_MANAGER * pManager,
   HWND hOwner )
{
   if( pManager == NULL )
      return FALSE;

   ZeroMemory(
      pManager,
      sizeof( HB_DOCK_GUIDE_MANAGER ) );

   pManager->hOwner = hOwner;

   hbDockGuideCreate(
      &pManager->Guides[0],
      hOwner,
      HB_DOCK_GUIDE_LEFT );

   hbDockGuideCreate(
      &pManager->Guides[1],
      hOwner,
      HB_DOCK_GUIDE_RIGHT );

   hbDockGuideCreate(
      &pManager->Guides[2],
      hOwner,
      HB_DOCK_GUIDE_TOP );

   hbDockGuideCreate(
      &pManager->Guides[3],
      hOwner,
      HB_DOCK_GUIDE_BOTTOM );

   hbDockGuideCreate(
      &pManager->Guides[4],
      hOwner,
      HB_DOCK_GUIDE_CENTER );

   return TRUE;
}

void hbDockGuideManagerDestroy(
   HB_DOCK_GUIDE_MANAGER * pManager )
{
   int i;

   if( pManager == NULL )
      return;

   for( i = 0; i < HB_DOCK_GUIDE_COUNT; ++i )
      hbDockGuideDestroy(
         &pManager->Guides[ i ] );
}
void hbDockGuideManagerPaint(
   HB_DOCK_GUIDE_MANAGER * pManager )
{
	int i;
	HDC hdc;

	hdc = GetDC(
			pManager->hOwner );
	if( pManager == NULL )
      return;

	for( i = 0; i < HB_DOCK_GUIDE_COUNT; ++i )
	{
      hbDockGuidePaint(
         &pManager->Guides[i],
         hdc );
	}
	ReleaseDC(
	   pManager->hOwner,
	   hdc );
}