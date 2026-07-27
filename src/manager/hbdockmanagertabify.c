#include <windows.h>

#include "hbdockmanagertabify.h"
#include "hbdockcontainer.h"
#include "hbdocktabgroup.h"
#include "hbdockmanagerrefreshlayout.h"
#include "hbdockmanagerundock.h"
#include "hbdockpaneldock.h"

/*
 * Nota de estabilizacion: esta funcion insertaba el panel en el
 * TabGroup del contenedor (estructura en memoria) pero nunca
 * disparaba un recalculo de layout real -- la ventana del panel
 * activo del grupo nunca se movia/mostraba. Es el mismo tipo de
 * hueco que hbDockManagerDockPanel (ver esa funcion): la insercion
 * en el arbol/grupo funcionaba, pero nada la traducia en pantalla.
 *
 * Nota de estabilizacion (2): pPanel->pContainer -- el enlace
 * inverso panel-a-contenedor -- nunca se asignaba en NINGUN lugar
 * de todo el proyecto, solo se leia (en hbDockManagerUndockPanel,
 * hbDockTabifyPanel de la fachada, etc). Eso hacia que esas
 * funciones fallaran siempre en silencio para cualquier panel
 * acoplado por el camino normal. Se corrige aca y en
 * hbdockmanagerdock.c.
 *
 * Nota de estabilizacion (3): si el panel que se esta tabificando
 * ya estaba acoplado en otro lado (pPanel->pContainer != NULL), hay
 * que sacarlo de ahi primero -- si no, el mismo panel queda
 * referenciado por dos contenedores a la vez (el viejo y el nuevo
 * grupo de tabs), y solo uno "gana" la posicion real en pantalla.
 */

BOOL hbDockManagerTabifyPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_CONTAINER * pContainer,
   HB_DOCK_PANEL * pPanel )
{
   if( pManager == NULL )
      return FALSE;

   if( pContainer == NULL )
      return FALSE;

   if( pPanel == NULL )
      return FALSE;

   if( pContainer->Type != HB_CONTAINER_TABS )
      return FALSE;

   /*
    * Nota de estabilizacion: si el panel ya esta en ESTE MISMO
    * contenedor (por ejemplo, el usuario aprieta "tabificar" dos
    * veces seguidas sobre el mismo destino), no hay que agregarlo
    * de nuevo -- eso duplicaba el panel adentro del TabGroup y
    * corrompia esa estructura (confirmado: dejaba toda la ventana
    * en blanco). Alcanza con dejarlo activo y salir.
    */
   if( pPanel->pContainer == pContainer )
   {
      UINT i;

      for( i = 0; i < pContainer->TabGroup.Count; i++ )
      {
         if( pContainer->TabGroup.Tabs[ i ].pPanel == pPanel )
         {
            hbDockTabGroupSetActive(
               &pContainer->TabGroup,
               i );

            break;
         }
      }

      return TRUE;
   }

   if( pPanel->pContainer != NULL )
   {
      hbDockManagerUndock(
         pManager,
         pPanel->pContainer );
   }

   if( !hbDockTabGroupAddPanel(
            &pContainer->TabGroup,
            pPanel ) )
      return FALSE;

   pPanel->pContainer = pContainer;

   hbDockPanelSetDockSite(
      pPanel,
      HB_DOCKSITE_CENTER );

   hbDockTabGroupSetActive(
      &pContainer->TabGroup,
      pContainer->TabGroup.Count - 1 );

   hbDockManagerRefreshLayout(
      pManager );

   return TRUE;
}