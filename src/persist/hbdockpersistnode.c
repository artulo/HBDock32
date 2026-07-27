#include <stdio.h>
#include <string.h>

#include "hbdockpersistnode.h"
#include "hbdockpersistcontainer.h"
#include "hbdocklayoutnodecreate.h"
#include "hbdocklayoutdestroy.h"

/*
 * Nota de estabilizacion (Etapa 7): hbDockSaveNode ya existia pero
 * solo guardaba Type y Ratio -- para un nodo hoja (HB_LAYOUT_LEAF)
 * nunca escribia el contenedor (pNode->pContainer), asi que al volver
 * a cargar un layout no habia forma de saber que paneles iban en cada
 * hoja. Se corrige para que las hojas llamen a hbDockSaveContainer, y
 * se agrega hbDockLoadNode (no existia).
 */

BOOL hbDockSaveNode(
      FILE * fp,
      const HB_DOCK_LAYOUT_NODE * pNode )
{
    if( pNode == NULL )
    {
        fprintf(
            fp,
            "null\n");

        return TRUE;
    }

    fprintf(
        fp,
        "%d %.4f\n",
        pNode->Type,
        pNode->Ratio);

    if( pNode->Type == HB_LAYOUT_LEAF )
    {
        return hbDockSaveContainer(
            fp,
            pNode->pContainer );
    }

    if( !hbDockSaveNode(
            fp,
            pNode->First) )
        return FALSE;

    return hbDockSaveNode(
        fp,
        pNode->Second);
}

BOOL hbDockLoadNode(
      FILE * fp,
      HB_DOCK_LAYOUT_NODE ** ppNode,
      HB_DOCK_PANEL_REGISTRY * pRegistry )
{
    char szLine[ 64 ];
    int iType;
    float fRatio;
    HB_DOCK_LAYOUT_NODE * pNode;

    if( ppNode == NULL )
        return FALSE;

    *ppNode = NULL;

    if( fgets( szLine, sizeof( szLine ), fp ) == NULL )
        return FALSE;

    if( strncmp( szLine, "null", 4 ) == 0 )
        return TRUE;

    if( sscanf( szLine, "%d %f", &iType, &fRatio ) != 2 )
        return FALSE;

    if( iType == HB_LAYOUT_LEAF )
    {
        HB_DOCK_CONTAINER * pContainer;

        if( !hbDockLoadContainer(
                fp,
                &pContainer,
                pRegistry ) )
            return FALSE;

        pNode = hbDockLayoutNodeCreateLeaf(
            pContainer );

        if( pNode == NULL )
            return FALSE;

        *ppNode = pNode;

        return TRUE;
    }

    {
        HB_DOCK_LAYOUT_NODE * pFirst;
        HB_DOCK_LAYOUT_NODE * pSecond;

        if( !hbDockLoadNode(
                fp,
                &pFirst,
                pRegistry ) )
            return FALSE;

        if( !hbDockLoadNode(
                fp,
                &pSecond,
                pRegistry ) )
        {
            hbDockLayoutDestroyNode( pFirst );
            return FALSE;
        }

        pNode = hbDockLayoutNodeCreateSplit(
            ( HB_LAYOUT_NODE_TYPE ) iType,
            pFirst,
            pSecond );

        if( pNode == NULL )
            return FALSE;

        pNode->Ratio = fRatio;

        *ppNode = pNode;

        return TRUE;
    }
}
