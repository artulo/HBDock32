#include <windows.h>

#include "hbdockmanager.h"
#include "hbdockdragcontroller.h"



BOOL hbDockManagerCreate(
      HB_DOCK_MANAGER * pManager,
      HWND hWnd )
{
    ZeroMemory(
        pManager,
        sizeof(HB_DOCK_MANAGER));

	pManager->pDragController =
	   ( HB_DOCK_DRAG_CONTROLLER * )
	   LocalAlloc(
		  LPTR,
		  sizeof( HB_DOCK_DRAG_CONTROLLER ) );

			if( pManager->pDragController == NULL )
			{
			   return FALSE;
			}

	hbDockDragControllerInit(
	   pManager->pDragController,
	   pManager );
	
	ZeroMemory(
		&pManager->Transaction,
		sizeof(pManager->Transaction));
	
	ZeroMemory(
		&pManager->Scheduler,
		sizeof(HB_DOCK_SCHEDULER));

    pManager->hMainWnd = hWnd;

    hbDockLayoutTreeInit(
        &pManager->LayoutTree);

  /*  hbDockGuideManagerInit(
        &pManager->GuideManager,
        hWnd);
*/
    hbDockPreviewOverlayCreate(
        &pManager->Preview,
        hWnd);

    hbDockDiamondCreate(
        &pManager->Diamond,
        hWnd);

    hbDockAutoHideAnimationManagerInit(
        &pManager->AnimationManager);
	
	hbDockPanelRegistryInit(
		&pManager->Registry );	
		
	hbDockCommandQueueInit(
		&pManager->CommandQueue);
	
	hbDockEventDispatcherInit(
		pManager );
		
	pManager->Dragging = FALSE;
	pManager->UpdatingLayout = FALSE;
	pManager->hCapturedWindow = NULL;	
	
    return TRUE;
}

void hbDockManagerDestroy(
      HB_DOCK_MANAGER * pManager )
{
    hbDockDiamondDestroy(
        &pManager->Diamond);

    hbDockPreviewOverlayDestroy(
        &pManager->Preview);

    hbDockGuideManagerDestroy(
        &pManager->GuideManager);

    hbDockAutoHideAnimationManagerDone(
        &pManager->AnimationManager);

    hbDockLayoutTreeDone(
        &pManager->LayoutTree);
	
	hbDockPanelRegistryDone(
		&pManager->Registry );
		
	if( pManager->pDragController != NULL )
	{
	   hbDockDragControllerCancel(
		  pManager->pDragController );

	   LocalFree(
		  pManager->pDragController );

	   pManager->pDragController = NULL;
	}
}