#ifndef HBDOCKDRAG_H
#define HBDOCKDRAG_H

#include <windows.h>

#include "hbdockguidemanager.h"
#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Etapa 20: de donde vino el ultimo hit-test de guia -- necesario
 * para saber si el drop debe ser relativo a un panel puntual
 * (diamante, sobre TargetNode) o relativo a toda la ventana
 * principal (guias externas, comportamiento de siempre).
 */
typedef enum
{
   HB_DOCK_GUIDE_SOURCE_NONE = 0,
   HB_DOCK_GUIDE_SOURCE_DIAMOND,
   HB_DOCK_GUIDE_SOURCE_OUTER

} HB_DOCK_GUIDE_SOURCE;

typedef struct _HB_DOCK_DRAG
{
   BOOL Dragging;

   HWND hWndSource;

   POINT StartPoint;

   POINT CurrentPoint;

   RECT DragRect;

   HB_DOCK_GUIDE_TYPE Guide;

   HB_DOCK_GUIDE_SOURCE GuideSource;

   /* Nodo hoja (con su contenedor) que esta debajo del mouse en este
    * momento del arrastre, si hay uno -- el diamante se centra sobre
    * el, y un drop sobre una de sus 5 zonas acopla relativo a EL en
    * vez de relativo a toda la ventana. NULL si el mouse no esta
    * sobre ningun panel acoplado. */
   HB_DOCK_LAYOUT_NODE * TargetNode;

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