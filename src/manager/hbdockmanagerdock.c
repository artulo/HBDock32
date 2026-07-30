#include <windows.h>
 
#include "hbdockmanagerdock.h"

#include "hbdocklayoutinsertpanel.h"
#include "hbdockcontainer.h"
#include "hbdockmanagertabify.h"
#include "hbdockmanagerrefreshlayout.h"
#include "hbdockmanagerundock.h"
#include "hbdockpaneldock.h"
#include "hbdockpanelparent.h"

static HB_DOCK_SITE hbDockGuideToSite(
   HB_DOCK_GUIDE_TYPE Guide )
{
   switch( Guide )
   {
      case HB_GUIDE_LEFT:
         return HB_DOCKSITE_LEFT;

      case HB_GUIDE_RIGHT:
         return HB_DOCKSITE_RIGHT;

      case HB_GUIDE_TOP:
         return HB_DOCKSITE_TOP;

      case HB_GUIDE_BOTTOM:
         return HB_DOCKSITE_BOTTOM;

      case HB_GUIDE_CENTER:
         return HB_DOCKSITE_CENTER;

      default:
         return HB_DOCKSITE_NONE;
   }
}

/*
 * Nota de estabilizacion: "acoplar al centro" (tabificar) solo
 * funcionaba cuando la raiz del arbol era exactamente una sola hoja
 * (el primer panel acoplado alguna vez) -- con mas de un panel ya
 * acoplados, la raiz pasa a ser un nodo de division, y el camino de
 * CENTER no sabia que hacer con eso (hbDockLayoutInsertPanel no
 * tiene un caso para HB_DOCKSITE_CENTER en su switch, cae al
 * default y devuelve FALSE en silencio). Se agrega esta funcion
 * para bajar por el arbol hasta encontrar la primera hoja
 * disponible y tabificar ahi, en vez de exigir que la raiz misma
 * sea una hoja.
 */
static HB_DOCK_LAYOUT_NODE * hbDockFindFirstLeaf(
   HB_DOCK_LAYOUT_NODE * pNode )
{
   if( pNode == NULL )
      return NULL;

   if( pNode->Type == HB_LAYOUT_LEAF )
      return pNode;

   if( pNode->First != NULL )
   {
      HB_DOCK_LAYOUT_NODE * pFound =
         hbDockFindFirstLeaf( pNode->First );

      if( pFound != NULL )
         return pFound;
   }

   return hbDockFindFirstLeaf( pNode->Second );
}

/*
 * Nota de estabilizacion: esta funcion insertaba el nuevo contenedor
 * en el arbol de layout (estructura en memoria, via
 * hbDockLayoutInsertPanel) pero nunca disparaba un recalculo real --
 * hbDockLayoutRecalc (la que de verdad mueve la ventana del panel,
 * Etapa 9) solo se llamaba desde otros caminos (undock, drag,
 * autohide, cargar workspace), nunca desde aca. Resultado: acoplar
 * un panel por primera vez insertaba todo bien en el arbol y
 * devolvia TRUE, pero la ventana real del panel se quedaba donde
 * estaba (invisible o superpuesta) hasta el primer resize manual de
 * la ventana principal. Se agrega el refresh en las 2 salidas
 * exitosas (la rama CENTER que tabifica, y la rama normal que
 * inserta un nodo nuevo).
 *
 * Nota de estabilizacion (2): pPanel->pContainer nunca se asignaba
 * en ningun lugar del proyecto, solo se leia -- se corrige aca.
 *
 * Nota de estabilizacion (3): si el panel ya estaba acoplado en
 * otro lado y se llama a Dock() de nuevo (por ejemplo, el usuario
 * aprieta "Acoplar a la izquierda" sobre un panel que ya esta
 * acoplado), hay que sacarlo de su posicion vieja primero. Si no,
 * el mismo panel queda referenciado por dos contenedores del arbol
 * a la vez, y el resultado visual queda roto (confirmado con
 * capturas reales: un recuadro huerfano mas dos paneles mal
 * ubicados).
 */

BOOL hbDockManagerDockPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_GUIDE_TYPE Guide )
{
   HB_DOCK_CONTAINER * pContainer;
   HB_DOCK_SITE Site;

   if( pManager == NULL )
      return FALSE;

   if( pPanel == NULL )
      return FALSE;

   Site =
      hbDockGuideToSite(
         Guide );

   if( Site == HB_DOCKSITE_NONE )
      return FALSE;

   if( pPanel->pContainer != NULL )
   {
      /*
       * Etapa 14: esto llamaba a hbDockManagerUndock directo sobre
       * pPanel->pContainer -- la version a nivel CONTENEDOR, que
       * saca el contenedor ENTERO del arbol. Si el panel estaba
       * tabificado junto con otro (por ejemplo Explorer+Props
       * despues de "Tab al centro"), el companero de pestaña se iba
       * de arrastre: quedaba huerfano, con su pContainer apuntando
       * a un contenedor ya desconectado del arbol (nunca se libera,
       * pero tampoco se vuelve a recorrer -- ni acoplado, ni oculto,
       * ni flotando). Es la misma clase de bug que ya se habia
       * corregido para AutoHide (ver hbDockManagerUndockPanel, que
       * SI distingue "sacar solo este panel de la pestaña" de
       * "sacar el contenedor entero") -- pero ese fix nunca se
       * aplico aca, en el camino de volver a acoplar un panel que
       * ya estaba acoplado en otro lado.
       */
      hbDockManagerUndockPanel(
         pManager,
         pPanel );
   }

   pContainer =
      ( HB_DOCK_CONTAINER * )
      LocalAlloc(
         LPTR,
         sizeof( HB_DOCK_CONTAINER ) );

   if( pContainer == NULL )
      return FALSE;

   if( !hbDockContainerCreate(
            pContainer,
            pManager->hMainWnd ) )
   {
      LocalFree(
         pContainer );

      return FALSE;
   }

   pContainer->Type =
      HB_CONTAINER_TABS;

   /*
    * Nota de estabilizacion: NO asignar pContainer->TabGroup.pPanel
    * directo aca -- eso dejaba TabGroup.Count en 0 aunque hubiera un
    * panel real en el contenedor (el panel vivia solo en el puntero
    * "activo", nunca en el arreglo Tabs[]). Si mas adelante se
    * tabifica OTRO panel sobre este mismo contenedor,
    * hbDockTabGroupAddPanel ve Count==0, asume que el grupo esta
    * vacio, y PISA esta referencia en vez de agregarse como segunda
    * pestana -- el panel original (Explorer, en el caso confirmado)
    * queda huerfano: su ventana sigue visible, congelada en su rect
    * viejo, y nada la vuelve a mover/ocultar nunca mas. Se usa
    * hbDockTabGroupAddPanel tambien para el dock inicial, para que
    * el grupo quede consistente (Count=1, Tabs[0]=panel) desde el
    * primer momento.
    */
   if( !hbDockTabGroupAddPanel(
            &pContainer->TabGroup,
            pPanel ) )
   {
      hbDockContainerDestroy(
         pContainer );

      LocalFree(
         pContainer );

      return FALSE;
   }

	if( Guide == HB_GUIDE_CENTER )
	{
	   HB_DOCK_LAYOUT_NODE * pNode;

	   pNode =
		  hbDockFindFirstLeaf(
		     pManager->LayoutTree.Root );

	   if( pNode != NULL )
	   {
			 BOOL bOk;

			 bOk = hbDockManagerTabifyPanel(
				pManager,
				pNode->pContainer,
				pPanel );

			 /* El contenedor local que reservamos arriba no hacia
			  * falta para este camino (se tabifica sobre el que ya
			  * existia) -- liberarlo aca. */
			 hbDockContainerDestroy(
				pContainer );

			 LocalFree(
				pContainer );

			 return bOk;
	   }
	}
	
   if( !hbDockLayoutInsertPanel(
            &pManager->LayoutTree,
            pManager->LayoutTree.Root,
            pContainer,
            Site ) )
   {
      hbDockContainerDestroy(
         pContainer );

      LocalFree(
         pContainer );

      return FALSE;
   }

   pPanel->pContainer = pContainer;

   /*
    * Etapa 13: si el panel venia de flotar, su ventana real seguia
    * siendo hija del popup flotante (SetParent en hbDockFloatingCreate,
    * ver hbdockfloating.c) -- sin este reparent, quedaba "acoplado"
    * en el arbol de layout pero invisible en pantalla, porque
    * MoveWindow/ShowWindow lo mueven relativo al padre equivocado
    * (el popup, ahora oculto). Para un panel que nunca floto, esto
    * es un no-op (ya es hijo de la ventana principal desde que se
    * creo, via TPanel:New en TDockPanel.prg).
    */
   hbDockPanelSetParent(
      pPanel,
      pManager->hMainWnd );

   hbDockPanelSetDockSite(
      pPanel,
      Site );

   hbDockManagerRefreshLayout(
      pManager );

   return TRUE;
}

/*
 * Etapa 20: acopla pPanel relativo a un nodo ESPECIFICO del arbol
 * (pTargetNode), no a la raiz/ventana completa -- usado por el
 * diamante durante el arrastre (a diferencia de las guias externas,
 * que siguen usando hbDockManagerDockPanel de arriba). Depende del
 * fix de hbDockLayoutInsertPanel que reconecta correctamente el
 * padre viejo de un target no-raiz.
 */
BOOL hbDockManagerDockRelative(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_LAYOUT_NODE * pTargetNode,
   HB_DOCK_GUIDE_TYPE Guide )
{
   HB_DOCK_CONTAINER * pContainer;
   HB_DOCK_SITE Site;

   if( pManager == NULL )
      return FALSE;

   if( pPanel == NULL )
      return FALSE;

   if( pTargetNode == NULL )
      return FALSE;

   Site =
      hbDockGuideToSite(
         Guide );

   if( Site == HB_DOCKSITE_NONE || Site == HB_DOCKSITE_CENTER )
      return FALSE;

   if( pPanel->pContainer != NULL )
      hbDockManagerUndockPanel(
         pManager,
         pPanel );

   /*
    * hbDockManagerUndockPanel (arriba) puede haber podado nodos del
    * arbol (RemoveEmpty/Optimize, via hbDockManagerUndock) si el
    * panel arrastrado compartia contenedor con otros -- eso no toca
    * a pTargetNode en si (sigue siendo un nodo valido del mismo
    * arbol, no fue el que se removio), asi que es seguro seguir
    * usandolo tal cual.
    */

   pContainer =
      ( HB_DOCK_CONTAINER * )
      LocalAlloc(
         LPTR,
         sizeof( HB_DOCK_CONTAINER ) );

   if( pContainer == NULL )
      return FALSE;

   if( !hbDockContainerCreate(
            pContainer,
            pManager->hMainWnd ) )
   {
      LocalFree(
         pContainer );

      return FALSE;
   }

   pContainer->Type =
      HB_CONTAINER_TABS;

   if( !hbDockTabGroupAddPanel(
            &pContainer->TabGroup,
            pPanel ) )
   {
      hbDockContainerDestroy(
         pContainer );

      LocalFree(
         pContainer );

      return FALSE;
   }

   if( !hbDockLayoutInsertPanel(
            &pManager->LayoutTree,
            pTargetNode,
            pContainer,
            Site ) )
   {
      hbDockContainerDestroy(
         pContainer );

      LocalFree(
         pContainer );

      return FALSE;
   }

   pPanel->pContainer = pContainer;

   hbDockPanelSetParent(
      pPanel,
      pManager->hMainWnd );

   hbDockPanelSetDockSite(
      pPanel,
      Site );

   hbDockManagerRefreshLayout(
      pManager );

   return TRUE;
}