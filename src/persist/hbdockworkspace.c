#include "hbdockworkspace.h"

#include "hbdockpersist.h"
#include "hbdockmanagerlayout.h"

BOOL hbDockWorkspaceSave(
      HB_DOCK_MANAGER * pManager,
      LPCTSTR pszFile )
{
    if( pManager == NULL )
        return FALSE;

    return hbDockSaveLayout(
        &pManager->LayoutTree,
        pszFile,
        HB_DOCK_FORMAT_XML);
}

BOOL hbDockWorkspaceLoad(
      HB_DOCK_MANAGER * pManager,
      LPCTSTR pszFile )
{
    BOOL bOk;

    if( pManager == NULL )
        return FALSE;

    bOk = hbDockLoadLayout(
        &pManager->LayoutTree,
        pszFile,
        &pManager->Registry);

    if( !bOk )
        return FALSE;

    /* Nota de estabilizacion (Etapa 7): tras cargar el arbol hay que
     * recalcular geometria y repintar -- sin esto el layout cargado
     * quedaria con Rect en cero hasta el primer resize manual. */
    hbDockManagerLayout(
        pManager );

    hbDockManagerInvalidateLayout(
        pManager );

    return TRUE;
}