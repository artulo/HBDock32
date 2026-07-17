#ifndef HBDOCKLAYOUTMUTATION_H
#define HBDOCKLAYOUTMUTATION_H

#include "hbdocklayouttree.h"
#include "hbdockpanelregistry.h"
#include "hbdockcontainer.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockLayoutInsertContainer(
        HB_DOCK_LAYOUT_TREE * pTree,
        HB_DOCK_CONTAINER * pContainer,
        UINT Side );

BOOL hbDockLayoutRemovePanel(
        HB_DOCK_LAYOUT_TREE * pTree,
        HB_DOCK_PANEL * pPanel );

BOOL hbDockLayoutMovePanel(
        HB_DOCK_LAYOUT_TREE * pTree,
        HB_DOCK_PANEL * pPanel,
        HB_DOCK_LAYOUT_NODE * pTarget,
        UINT Side );

BOOL hbDockLayoutTabifyPanel(
        HB_DOCK_LAYOUT_TREE * pTree,
        HB_DOCK_PANEL * pSource,
        HB_DOCK_PANEL * pTarget );

BOOL hbDockLayoutCompact(
        HB_DOCK_LAYOUT_TREE * pTree );

#ifdef __cplusplus
}
#endif

#endif