#ifndef HBDOCKLAYOUTTREE_H
#define HBDOCKLAYOUTTREE_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif


/* Tipos de nodo del árbol */

typedef enum
{
   HB_LAYOUT_LEAF = 0,
   HB_LAYOUT_HORIZONTAL,
   HB_LAYOUT_VERTICAL

} HB_LAYOUT_NODE_TYPE;



/* Nodo del árbol de layout */

typedef struct _HB_DOCK_LAYOUT_NODE
{
   HB_LAYOUT_NODE_TYPE Type;


   RECT Rect;


   /* Relación de división */

   float Ratio;


   /* Posición del splitter */

   int SplitPos;


   /* Tamaño del splitter */

   int SplitterSize;


   /*
    * Contenedor asociado al nodo hoja.
    *
    * NOTA DE ESTABILIZACION (Etapa 7): este campo se llamaba "pPanel"
    * y era de tipo HB_DOCK_PANEL* -- pero las 4 funciones que crean
    * nodos hoja (hbDockLayoutNodeCreateLeaf y sus llamadores en
    * hbdocklayoutinsertpanel.c, hbdocklayoutcopy.c, hbdocklayoutclone.c,
    * hbdocklayoutdeserialize.c) siempre pasan un HB_DOCK_CONTAINER*, y
    * 126 usos en src/manager, src/host, src/dock, src/layout, etc. ya
    * acceden a pNode->pContainer (un miembro que no existia). Sin este
    * fix, ninguno de esos archivos podia compilar. Se corrige el campo
    * para que coincida con el uso real y mayoritario.
    */

   HB_DOCK_CONTAINER * pContainer;


   /*
    * Relaciones del árbol
    */

   struct _HB_DOCK_LAYOUT_NODE * Parent;

   struct _HB_DOCK_LAYOUT_NODE * First;

   struct _HB_DOCK_LAYOUT_NODE * Second;


} HB_DOCK_LAYOUT_NODE;



/* Árbol completo */

typedef struct _HB_DOCK_LAYOUT_TREE
{
   HB_DOCK_LAYOUT_NODE * Root;

} HB_DOCK_LAYOUT_TREE;



BOOL hbDockLayoutTreeInit(
   HB_DOCK_LAYOUT_TREE * pTree );


void hbDockLayoutTreeDone(
   HB_DOCK_LAYOUT_TREE * pTree );



#ifdef __cplusplus
}
#endif

#endif /* HBDOCKLAYOUTTREE_H */