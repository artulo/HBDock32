#include <stdlib.h>

#include "hbdocklayoutmutation.h"
#include "hbdocklayoutnodecreate.h"
#include "hbdocklayoutinsert.h"
#include "hbdockcontainer.h"
#include "hbdockcontainerfactory.h"
#include "hbdocklayoutfind.h"
#include "hbdocklayoutdetach.h"
#include "hbdocklayoutinsertnode.h"
#include "hbdocklayoutrelative.h" 
#include "hbdockcontaineraddtab.h"


BOOL hbDockLayoutInsertContainer(
        HB_DOCK_LAYOUT_TREE * pTree,
        HB_DOCK_CONTAINER * pContainer,
        UINT Side )
{
    HB_DOCK_LAYOUT_NODE * pNode;

    if( pContainer == NULL )
        return FALSE;

    pNode = hbDockLayoutCreateLeaf( pContainer );

    if( pNode == NULL )
        return FALSE;

	pNode = hbDockLayoutCreateLeaf( pContainer );

    if( pNode == NULL )
        return FALSE;

    pNode->pContainer = pContainer;

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
		HB_DOCK_LAYOUT_NODE * pNode;
		HB_DOCK_CONTAINER * pContainer;

		pNode = hbDockLayoutFindPanel(
            pTree,
            pTarget );

		if( pNode == NULL )
			return FALSE;

		pContainer = pNode->pContainer;

		return hbDockContainerAddTab(
            pContainer,
            pSource->hWnd,
            pSource->Caption );
}


