#ifndef HBDOCKCONTAINER_H
#define HBDOCKCONTAINER_H

#include <windows.h>

#include "hbdockpanel.h"
#include "hbdocktabgroup.h"


#ifdef __cplusplus
extern "C" {
#endif


/*
 * Tipo de contenedor Dock
 */

typedef enum _HB_DOCK_CONTAINER_TYPE
{
   HB_CONTAINER_EMPTY = 0,

   HB_CONTAINER_TABS,

   HB_CONTAINER_SPLIT

} HB_DOCK_CONTAINER_TYPE;



typedef struct _HB_DOCK_CONTAINER
{
   /*
    * Tipo interno del contenedor
    */
   HB_DOCK_CONTAINER_TYPE Type;



   /*
    * Ventanas asociadas
    */
   HWND hWnd;

   HWND hParent;



   /*
    * Área del contenedor
    */
   RECT Rect;



   /*
    * Grupo de pestañas
    */
   HB_DOCK_TAB_GROUP TabGroup;



   /*
    * Panel activo
    */
   HB_DOCK_PANEL * pActivePanel;



   /*
    * Estado visible
    */
   BOOL Visible;



} HB_DOCK_CONTAINER;




BOOL hbDockContainerCreate(
   HB_DOCK_CONTAINER * pContainer,
   HWND hParent );



void hbDockContainerDestroy(
   HB_DOCK_CONTAINER * pContainer );



#ifdef __cplusplus
}
#endif


#endif /* HBDOCKCONTAINER_H */