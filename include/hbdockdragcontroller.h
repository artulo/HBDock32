#ifndef HBDOCKDRAGCONTROLLER_H
#define HBDOCKDRAGCONTROLLER_H

#include <windows.h>

#include "hbdockmanager.h"
#include "hbdockpanel.h"
#include "hbdockguidemanager.h"
#include "hbdockdrag.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_DRAG_CONTROLLER
{
   HB_DOCK_MANAGER * pManager;

   HB_DOCK_PANEL * pPanel;

   HB_DOCK_DRAG Drag;

} HB_DOCK_DRAG_CONTROLLER;


/*--------------------------------------------------------------------*/
/* Inicialización                                                     */
/*--------------------------------------------------------------------*/

void hbDockDragControllerInit(
   HB_DOCK_DRAG_CONTROLLER * pController,
   HB_DOCK_MANAGER * pManager );


/*--------------------------------------------------------------------*/
/* Inicio del arrastre                                                */
/*--------------------------------------------------------------------*/

BOOL hbDockDragControllerBegin(
   HB_DOCK_DRAG_CONTROLLER * pController,
   HB_DOCK_PANEL * pPanel,
   HWND hWnd,
   POINT pt );


/*--------------------------------------------------------------------*/
/* Movimiento                                                         */
/*--------------------------------------------------------------------*/

void hbDockDragControllerMove(
   HB_DOCK_DRAG_CONTROLLER * pController,
   POINT pt );


/*--------------------------------------------------------------------*/
/* Finalización                                                       */
/*--------------------------------------------------------------------*/

void hbDockDragControllerEnd(
   HB_DOCK_DRAG_CONTROLLER * pController );


/*--------------------------------------------------------------------*/
/* Cancelación                                                        */
/*--------------------------------------------------------------------*/

void hbDockDragControllerCancel(
   HB_DOCK_DRAG_CONTROLLER * pController );


/*--------------------------------------------------------------------*/
/* Hit Test                                                           */
/*--------------------------------------------------------------------*/

HB_DOCK_GUIDE_TYPE hbDockDragHitTest(
   HB_DOCK_DRAG_CONTROLLER * pController );


/*--------------------------------------------------------------------*/
/* Estado                                                             */
/*--------------------------------------------------------------------*/

BOOL hbDockDragIsDragging(
   const HB_DOCK_DRAG_CONTROLLER * pController );


/*--------------------------------------------------------------------*/
/* Panel activo                                                       */
/*--------------------------------------------------------------------*/

HB_DOCK_PANEL * hbDockDragGetPanel(
   const HB_DOCK_DRAG_CONTROLLER * pController );


/*--------------------------------------------------------------------*/
/* Punto actual                                                       */
/*--------------------------------------------------------------------*/

POINT hbDockDragGetPoint(
   const HB_DOCK_DRAG_CONTROLLER * pController );


/*--------------------------------------------------------------------*/
/* Rectángulo actual                                                  */
/*--------------------------------------------------------------------*/

RECT hbDockDragGetRect(
   const HB_DOCK_DRAG_CONTROLLER * pController );


/*--------------------------------------------------------------------*/
/* Ventana origen                                                     */
/*--------------------------------------------------------------------*/

HWND hbDockDragGetSourceWindow(
   const HB_DOCK_DRAG_CONTROLLER * pController );

#ifdef __cplusplus
}
#endif

#endif