
#include "hbdockgeometry.h"

BOOL hbDockGeometryCalculate(
        HB_DOCK_LAYOUT_TREE * pTree,
        const RECT * pClient )
{
    if( pTree == NULL )
        return FALSE;

    if( pTree->Root == NULL )
        return TRUE;

    return hbDockGeometryNode(
                pTree->Root,
                pClient );
}

BOOL hbDockGeometryNode(
        HB_DOCK_LAYOUT_NODE * pNode,
        const RECT * pRect )
{
    RECT rc1;
    RECT rc2;

    if( pNode == NULL )
        return FALSE;

    pNode->Geometry.Bounds = *pRect;

    if( pNode->Type == HB_LAYOUT_LEAF )
    {
        pNode->Geometry.Client = *pRect;

        return TRUE;
    }

    switch( pNode->Orientation )
    {
        case HB_SPLIT_VERTICAL:

            hbDockGeometrySplitVertical(
                    pRect,
                    pNode->Ratio,
                    &rc1,
                    &rc2 );

            hbDockGeometryNode(
                    pNode->Child1,
                    &rc1 );

            hbDockGeometryNode(
                    pNode->Child2,
                    &rc2 );

            break;

        case HB_SPLIT_HORIZONTAL:

            hbDockGeometrySplitHorizontal(
                    pRect,
                    pNode->Ratio,
                    &rc1,
                    &rc2 );

            hbDockGeometryNode(
                    pNode->Child1,
                    &rc1 );

            hbDockGeometryNode(
                    pNode->Child2,
                    &rc2 );

            break;
    }

    return TRUE;
}

