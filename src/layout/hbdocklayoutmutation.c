#include <stdlib.h>

#include "hbdocklayoutmutation.h"

BOOL hbDockLayoutInsertPanel(
        HB_DOCK_LAYOUT_TREE * pTree,
        HB_DOCK_PANEL * pPanel,
        UINT Side )
{
    HB_DOCK_LAYOUT_NODE * pNode;

    pNode = hbDockLayoutCreateLeaf();

    if( pNode == NULL )
        return FALSE;

    pNode->Panel = pPanel;

    if( pTree->Root == NULL )
    {
        pTree->Root = pNode;
        return TRUE;
    }

    return hbDockLayoutInsertNode(
                pTree,
                pNode,
                Side );
}

BOOL hbDockLayoutRemovePanel(
        HB_DOCK_LAYOUT_TREE * pTree,
        HB_DOCK_PANEL * pPanel )
{
    HB_DOCK_LAYOUT_NODE * pNode;

    pNode =
        hbDockLayoutFindPanel(
            pTree,
            pPanel );

    if( pNode == NULL )
        return FALSE;

    hbDockLayoutDetachNode(
        pTree,
        pNode );

    hbDockLayoutCompact(
        pTree );

    return TRUE;
}

BOOL hbDockLayoutMovePanel(
        HB_DOCK_LAYOUT_TREE * pTree,
        HB_DOCK_PANEL * pPanel,
        HB_DOCK_LAYOUT_NODE * pTarget,
        UINT Side )
{
    if( !hbDockLayoutRemovePanel(
            pTree,
            pPanel ) )
        return FALSE;

    return hbDockLayoutInsertRelative(
            pTree,
            pPanel,
            pTarget,
            Side );
}

BOOL hbDockLayoutTabifyPanel(
        HB_DOCK_LAYOUT_TREE * pTree,
        HB_DOCK_PANEL * pSource,
        HB_DOCK_PANEL * pTarget )
{
    HB_DOCK_CONTAINER * pContainer;

    pContainer =
        hbDockLayoutFindContainer(
            pTree,
            pTarget );

    if( pContainer == NULL )
        return FALSE;

    return hbDockContainerAddTab(
                pContainer,
                pSource );
}


