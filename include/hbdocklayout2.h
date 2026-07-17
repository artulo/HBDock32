#ifndef HBDOCKLAYOUT2_H
#define HBDOCKLAYOUT2_H


#include "hbdocktypes.h"


/*
   Inserción de nodos
*/
HB_DOCK_NODE *
hbDockLayoutInsertNode(
        HB_DOCK_LAYOUT *layout,
        HB_DOCK_NODE *parent,
        HB_DOCK_NODE *node
);


/*
   Búsqueda
*/
HB_DOCK_PANEL *
hbDockLayoutFindPanel(
        HB_DOCK_NODE *root,
        int panelId
);


HB_DOCK_NODE *
hbDockLayoutFindContainer(
        HB_DOCK_NODE *root,
        int containerId
);


/*
   Detach
*/
HB_DOCK_NODE *
hbDockLayoutDetachNode(
        HB_DOCK_LAYOUT *layout,
        HB_DOCK_NODE *node
);


/*
   Inserción relativa
*/
HB_DOCK_NODE *
hbDockLayoutInsertRelative(
        HB_DOCK_LAYOUT *layout,
        HB_DOCK_NODE *reference,
        HB_DOCK_NODE *node,
        int position
);


/*
   Operaciones de contenedores
*/
int
hbDockContainerAddTab(
        HB_DOCK_CONTAINER *container,
        HB_DOCK_PANEL *panel
);



/*
   Mutaciones del layout
*/
int
hbDockLayoutInsertContainer(
        HB_DOCK_LAYOUT *layout,
        HB_DOCK_CONTAINER *container
);


int
hbDockLayoutRemovePanel(
        HB_DOCK_LAYOUT *layout,
        int panelId
);


int
hbDockLayoutMovePanel(
        HB_DOCK_LAYOUT *layout,
        int panelId,
        HB_DOCK_NODE *target
);


int
hbDockLayoutTabifyPanel(
        HB_DOCK_LAYOUT *layout,
        int panelId,
        int targetContainer
);


#endif