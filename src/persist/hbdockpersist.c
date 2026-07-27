#include <stdio.h>
#include <string.h>

#include "hbdockpersist.h"
#include "hbdockpersistnode.h"
#include "hbdocklayoutdestroy.h"

/*
 * Nota de estabilizacion (Etapa 7): hbDockSaveLayout/hbDockLoadLayout
 * ya declaraban 3 formatos (XML/JSON/Binario) via hbDockSaveXML,
 * hbDockSaveJSON, hbDockSaveBinary, hbDockLoadXML -- pero NINGUNA de
 * esas 6 funciones tenia implementacion en ningun archivo del
 * proyecto. Si algo llegaba a llamar a hbDockSaveLayout, el enlazador
 * fallaba con 6 "unresolved external" de una sola vez.
 *
 * Se reemplaza por una implementacion real y funcional usando el
 * formato de texto simple de hbDockSaveNode/hbDockLoadNode (linea por
 * linea: tipo de nodo, ratio, y para las hojas el contenedor con el
 * Name persistente de cada panel). Los 3 valores de HB_DOCK_SAVE_FORMAT
 * se mantienen en el enum para no romper la firma publica, pero los
 * 3 guardan/cargan con este mismo formato de texto por ahora -- XML,
 * JSON y Binario reales quedan pendientes si se necesitan mas
 * adelante (son formatos distintos, no una simple renombrada).
 */

BOOL hbDockSaveLayout(
    const HB_DOCK_LAYOUT_TREE * pTree,
    LPCTSTR pszFile,
    HB_DOCK_SAVE_FORMAT Format )
{
    FILE * fp;
    BOOL bOk;

    ( void ) Format;

    if( pTree == NULL || pszFile == NULL )
        return FALSE;

    fp = fopen( pszFile, "w" );

    if( fp == NULL )
        return FALSE;

    fprintf( fp, "HBDOCKLAYOUT 1\n" );

    bOk = hbDockSaveNode(
        fp,
        pTree->Root );

    fclose( fp );

    return bOk;
}

BOOL hbDockLoadLayout(
    HB_DOCK_LAYOUT_TREE * pTree,
    LPCTSTR pszFile,
    HB_DOCK_PANEL_REGISTRY * pRegistry )
{
    FILE * fp;
    char szHeader[ 32 ];
    HB_DOCK_LAYOUT_NODE * pRoot;

    if( pTree == NULL || pszFile == NULL )
        return FALSE;

    fp = fopen( pszFile, "r" );

    if( fp == NULL )
        return FALSE;

    if( fgets( szHeader, sizeof( szHeader ), fp ) == NULL ||
        strncmp( szHeader, "HBDOCKLAYOUT", 12 ) != 0 )
    {
        fclose( fp );
        return FALSE;
    }

    if( !hbDockLoadNode(
            fp,
            &pRoot,
            pRegistry ) )
    {
        fclose( fp );
        return FALSE;
    }

    fclose( fp );

    if( pTree->Root != NULL )
        hbDockLayoutDestroyNode( pTree->Root );

    pTree->Root = pRoot;

    return TRUE;
}
