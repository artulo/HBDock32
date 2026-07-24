#ifndef HBDOCKDRAG_H
#define HBDOCKDRAG_H

#include <windows.h>

#include "hbdockguidemanager.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_DRAG
{
   BOOL Dragging;

   HWND hWndSource;

   POINT StartPoint;

   POINT CurrentPoint;

   RECT DragRect;

   HB_DOCK_GUIDE_TYPE Guide;

} HB_DOCK_DRAG;


/*----------------------------------------------------------*/
/* Inicialización                                           */
/*----------------------------------------------------------*/

void hbDockDragInit(
   HB_DOCK_DRAG * pDrag );


/*----------------------------------------------------------*/
/* Inicio del arrastre                                      */
/*----------------------------------------------------------*/

void hbDockDragBegin(
   HB_DOCK_DRAG * pDrag,
   HWND hWnd,
   POINT pt );


/*----------------------------------------------------------*/
/* Actualización                                             */
/*----------------------------------------------------------*/

void hbDockDragUpdate(
   HB_DOCK_DRAG * pDrag,
   POINT pt );


/*----------------------------------------------------------*/
/* Finalización                                             */
/*----------------------------------------------------------*/

void hbDockDragEnd(
   HB_DOCK_DRAG * pDrag );


/*----------------------------------------------------------*/
/* Cancelación                                              */
/*----------------------------------------------------------*/

void hbDockDragCancel(
   HB_DOCK_DRAG * pDrag );


#ifdef __cplusplus
}
#endif

#endif /* HBDOCKDRAG_H */