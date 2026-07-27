#include <windows.h>

#include "hbdockmanager.h"
#include "hbdockdragcontroller.h"
#include "hbdockguidemanager.h"
#include "hbdockhost.h"
#include "hbdockmanagerkeepontop.h"



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

    /* Nota de estabilizacion (Etapa 6): esta llamada estaba comentada
     * y ademas usaba un nombre que nunca existio (hbDockGuideManagerInit).
     * La funcion real es hbDockGuideManagerCreate (ver src/guides/
     * hbdockguidemanager.c, ya estabilizada en Etapa 1) -- sin esto,
     * pManager->GuideManager quedaba en ceros: sus ventanas de guia y
     * su diamante nunca se creaban, y hbDockGuideManagerShow (que sí
     * se llama de verdad al iniciar un arrastre, ver Etapa 4) hacia
     * ShowWindow sobre HWNDs invalidos. */
    hbDockGuideManagerCreate(
        &pManager->GuideManager,
        hWnd);
    hbDockPreviewOverlayCreate(
        &pManager->Preview,
        hWnd);

    hbDockDiamondCreate(
        &pManager->Diamond,
        hWnd);

    hbDockAutoHideAnimationManagerInit(
        &pManager->AnimationManager);

    /* Etapa 11: timer real que hace avanzar el motor de animacion de
     * AutoHide (Etapa 5) -- antes nada lo llamaba nunca. Se arranca
     * un solo timer por manager, sobre la ventana principal, en vez
     * de uno por panel (el diseño original de hbDockAutoHideStartTimer
     * usaba SetTimer sobre pPanel->hWnd, la ventana del propio
     * control del usuario -- no es nuestra para interceptar mensajes). */
    if( SetTimer(
            hWnd,
            HBDOCK_ANIMATION_TIMER_ID,
            pManager->AnimationManager.Interval,
            NULL ) != 0 )
    {
        pManager->AnimationManager.Running = TRUE;
    }
	
	hbDockPanelRegistryInit(
		&pManager->Registry );	
		
	hbDockCommandQueueInit(
		&pManager->CommandQueue);
	
	hbDockEventDispatcherInit(
		pManager );
		
	pManager->Dragging = FALSE;
	pManager->UpdatingLayout = FALSE;
	pManager->hCapturedWindow = NULL;	

    /*
     * Etapa 13: paneles flotantes no deben quedar tapados detras de
     * la ventana principal al clickearla (ver
     * hbdockmanagerkeepontop.c para el detalle completo).
     */
    hbDockManagerKeepFloatingOnTopInstall(
        pManager );

    return TRUE;
}

void hbDockManagerDestroy(
      HB_DOCK_MANAGER * pManager )
{
    /*
     * Etapa 13: restaurar el WndProc original de la ventana
     * principal ANTES de liberar cualquier otra cosa del manager --
     * si algun mensaje llega mientras se esta destruyendo, no debe
     * intentar leer un HB_DOCK_MANAGER a medio liberar.
     */
    hbDockManagerKeepFloatingOnTopRemove(
        pManager );

    if( pManager->AnimationManager.Running )
    {
        KillTimer(
            pManager->hMainWnd,
            HBDOCK_ANIMATION_TIMER_ID );

        pManager->AnimationManager.Running = FALSE;
    }

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