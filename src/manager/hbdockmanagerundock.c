#include <windows.h>

#include "hbdockmanagerundock.h"

#include "hbdocklayoutremovepanel.h"
#include "hbdocklayoutremoveempty.h"
#include "hbdocklayoutoptimizer.h"
#include "hbdocklayoutrecalc.h"
#include "hbdockmanagerrefreshlayout.h"
#include "hbdocktabgroup.h"
#include "hbdockcontainer.h"

BOOL hbDockManagerUndock(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_CONTAINER * pContainer )
{
   RECT rcOld;

   if( pManager == NULL )
      return FALSE;

   if( pContainer == NULL )
      return FALSE;

   /*
    * Etapa 71: capturar el rect ANTES de sacarlo del arbol/destruirlo,
    * para poder invalidar esa zona despues -- ver nota mas abajo.
    */
   rcOld = pContainer->Rect;

   if( !hbDockLayoutRemovePanel(
            &pManager->LayoutTree,
            pContainer ) )
      return FALSE;

   /*
    * Etapa 25: pContainer ya salio del arbol de layout (el nodo que
    * lo referenciaba fue liberado por hbDockLayoutRemovePanel) --
    * pero el struct HB_DOCK_CONTAINER en si (alocado con LocalAlloc
    * en hbDockManagerDockPanel/TabifyPanel/DockRelative) nunca se
    * liberaba. Era una fuga de memoria silenciosa desde siempre;
    * ahora tambien fuga una ventana real de Windows (la de caption,
    * ver hbdockcaptionwindow.c) cada vez que un panel se
    * desacopla/flota/autohide desde un contenedor solitario --
    * mucho mas visible que una fuga de heap. Esta funcion es hoy el
    * unico lugar de todo el proyecto donde un contenedor sale del
    * arbol por completo, asi que es el lugar correcto para
    * destruirlo.
    */
   hbDockContainerDestroy(
      pContainer );

   LocalFree(
      pContainer );

   /*
    * Etapa 71: pedido explicito -- artefacto visual confirmado (el
    * color de fondo VIEJO del panel/contenedor que se acaba de sacar
    * del arbol quedaba pintado en pantalla hasta que algo mas
    * repintara esa zona). Con WS_CLIPCHILDREN (Etapa 69), la ventana
    * principal ya no pinta por encima de sus hijos por defecto, asi
    * que la zona que un contenedor deja vacante necesita quedar
    * marcada sucia explicitamente para que se borre y repinte bien.
    */
   InvalidateRect(
      pManager->hMainWnd,
      &rcOld,
      TRUE );

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