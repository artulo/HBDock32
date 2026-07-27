#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "hbdockpersistcontainer.h"
#include "hbdockpanelfind.h"

/*
 * Nota de estabilizacion (Etapa 7): hbDockSaveContainer ya existia
 * pero guardaba pTab->Caption (texto de pantalla, puede repetirse o
 * cambiar de idioma) en vez de pPanel->Name (el identificador estable
 * del panel, el mismo que usa el Registry para hbDockPanelFindName).
 * Guardando el Caption no habia forma de reconstruir el panel real al
 * cargar. Se corrige para guardar el Name, y se agrega la contraparte
 * hbDockLoadContainer (no existia).
 */

BOOL hbDockSaveContainer(
      FILE * fp,
      const HB_DOCK_CONTAINER * pContainer )
{
    UINT i;

    if( pContainer == NULL )
    {
        fprintf(
            fp,
            "container-null\n");

        return TRUE;
    }

    fprintf(
        fp,
        "container %d %u\n",
        pContainer->Type,
        pContainer->TabGroup.Count);

    for(i=0;
        i<pContainer->TabGroup.Count;
        i++)
    {
        HB_DOCK_PANEL * pPanel;

        pPanel = pContainer->TabGroup.Tabs[i].pPanel;

        fprintf(
            fp,
            "%s\n",
            ( pPanel != NULL ) ? pPanel->Name : "" );
    }

    return TRUE;
}

BOOL hbDockLoadContainer(
      FILE * fp,
      HB_DOCK_CONTAINER ** ppContainer,
      HB_DOCK_PANEL_REGISTRY * pRegistry )
{
    char szLine[ 256 ];
    int iType;
    UINT nCount;
    UINT i;
    HB_DOCK_CONTAINER * pContainer;

    if( ppContainer == NULL )
        return FALSE;

    *ppContainer = NULL;

    if( fgets( szLine, sizeof( szLine ), fp ) == NULL )
        return FALSE;

    if( strncmp( szLine, "container-null", 14 ) == 0 )
        return TRUE;

    if( sscanf( szLine, "container %d %u", &iType, &nCount ) != 2 )
        return FALSE;

    pContainer =
        ( HB_DOCK_CONTAINER * )
        LocalAlloc(
            LPTR,
            sizeof( HB_DOCK_CONTAINER ) );

    if( pContainer == NULL )
        return FALSE;

    if( !hbDockContainerCreate(
            pContainer,
            NULL ) )
    {
        LocalFree( pContainer );
        return FALSE;
    }

    pContainer->Type = ( HB_DOCK_CONTAINER_TYPE ) iType;

    for( i = 0; i < nCount; i++ )
    {
        size_t nLen;
        HB_DOCK_PANEL * pPanel;

        if( fgets( szLine, sizeof( szLine ), fp ) == NULL )
        {
            hbDockContainerDestroy( pContainer );
            LocalFree( pContainer );
            return FALSE;
        }

        nLen = strlen( szLine );

        if( nLen > 0 && szLine[ nLen - 1 ] == '\n' )
            szLine[ nLen - 1 ] = '\0';

        pPanel = NULL;

        if( szLine[ 0 ] != '\0' && pRegistry != NULL )
        {
            pPanel = hbDockPanelFindName(
                pRegistry,
                szLine );
        }

        /* Si el panel ya no existe en el Registry (por ejemplo, el
         * layout guardado es de una version anterior de la app con
         * paneles que ya no se registran), se omite esa pestana en
         * vez de fallar toda la carga. */
        if( pPanel != NULL )
        {
            hbDockTabGroupAddPanel(
                &pContainer->TabGroup,
                pPanel );
        }
    }

    *ppContainer = pContainer;

    return TRUE;
}
