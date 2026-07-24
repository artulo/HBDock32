#ifndef HBDOCKLAYOUTINSERT_H
#define HBDOCKLAYOUTINSERT_H

#include "hbdocklayouttree.h"
#include "hbdockcontainer.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif
 
/* Inserta un panel en el árbol */
BOOL hbDockLayoutInsertPanel(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_PANEL * pPanel,
   int Side );

/* Crea el nodo raíz */
BOOL hbDockLayoutInsertRoot(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_CONTAINER * pContainer );

/* Divide un nodo hoja */
BOOL hbDockLayoutSplitLeaf(
   HB_DOCK_LAYOUT_NODE * pLeaf,
   HB_DOCK_CONTAINER * pNewContainer,
   HB_LAYOUT_NODE_TYPE SplitType );

#ifdef __cplusplus
}
#endif

#endif /* HBDOCKLAYOUTINSERT_H */