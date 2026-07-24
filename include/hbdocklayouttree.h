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
    * Panel asociado al nodo hoja
    */

   HB_DOCK_PANEL * pPanel;


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