#include <windows.h>

#include "hbdockmanagerundock.h"

#include "hbdocklayoutremovepanel.h"
#include "hbdocklayoutremoveempty.h"
#include "hbdocklayoutoptimizer.h"
#include "hbdocklayoutrecalc.h"
#include "hbdockmanagerrefreshlayout.h"
#include "hbdocktabgroup.h"

BOOL hbDockManagerUndock(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_CONTAINER * pContainer )
{
   if( pManager == NULL )
      return FALSE;

   if( pContainer == NULL )
      return FALSE;

   if( !hbDockLayoutRemovePanel(
            &pManager->LayoutTree,
            pContainer ) )
      return FALSE;

   return hbDockManagerRefreshLayout(
      pManager );
}

/*
 * Nota de estabilizacion: hbDockManagerUndockPanel estaba declarada
 * en el header y se llama de verdad desde hbDockManagerAutoHidePanel
 * (la funcion detras de HBDockAutoHide(), usada en los 3 ejemplos)
 * pero no tenia ninguna implementacion en todo el proyecto -- otro
 * "unresolved external" del mismo tipo que hbDockManagerBeginDrag
 * (Etapa 4), hbDockGuideManagerCreate (Etapa 6) y hbDockManagerFloatPanel
 * (Etapa 8). Es un wrapper fino: resuelve el contenedor del panel y
 * delega en hbDockManagerUndock, que ya funciona.
 */
void hbDockManagerUndockPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_CONTAINER * pContainer;

   if( pManager == NULL )
      return;

   if( pPanel == NULL )
      return;

   if( pPanel->pContainer == NULL )
      return;

   pContainer = pPanel->pContainer;

   /*
    * Nota de estabilizacion: si el panel esta tabificado junto con
    * otros en el mismo contenedor, sacar el contenedor ENTERO del
    * arbol (como hacia esta funcion antes) tambien se llevaba de
    * arrastre a los demas paneles del grupo -- quedaban huerfanos,
    * ni acoplados ni ocultos ni flotando, con su pContainer
    * apuntando a un contenedor ya desconectado del arbol.
    * Confirmado con captura real: AutoHide sobre un panel tabificado
    * hacia desaparecer TODO (el propio panel y su compañero de
    * pestaña). Si hay mas de un panel en el grupo, alcanza con sacar
    * solo este de la pestaña -- el contenedor se queda en el arbol
    * con los que quedan.
    */
   if( pContainer->TabGroup.Count > 1 )
   {
      hbDockTabGroupRemovePanel(
         &pContainer->TabGroup,
         pPanel );

      pPanel->pContainer = NULL;

      hbDockManagerRefreshLayout(
         pManager );

      return;
   }

   hbDockManagerUndock(
      pManager,
      pContainer );

   pPanel->pContainer = NULL;
}