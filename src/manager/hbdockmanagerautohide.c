#include "hbdockmanagerautohide.h"

#include "hbdockmanagerundock.h"
#include "hbdockmanagerlayout.h"
#include "hbdockmanagerrefreshlayout.h"
#include "hbdockmanagerdock.h"

#include "hbdocklayoutinsertpanel.h"

#include "hbdockpaneldock.h"

#include "hbdockarray.h"
#include "hbdockconfig.h"
#include "hbdockautohideslideengine.h"
#include "hbdockautohideanimationadd.h"

static HB_DOCK_AUTOHIDE * hbDockManagerFindAutoHide(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   int i;

   for( i = 0; i < pManager->AutoHideManager.Panes.Count; ++i )
   {
      HB_DOCK_AUTOHIDE * pAutoHide =
         ( HB_DOCK_AUTOHIDE * ) hbDockArrayGet(
            &pManager->AutoHideManager.Panes,
            i );

      if( pAutoHide != NULL && pAutoHide->Panel == pPanel )
         return pAutoHide;
   }

   return NULL;
}

static void hbDockManagerCalcAutoHideRects(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_SITE Site,
   RECT * pHidden,
   RECT * pVisible )
{
   RECT rc;
   int cx;
   int cy;

   GetClientRect(
      pManager->hMainWnd,
      &rc );

   cx = pPanel->DockSize.cx > 0 ?
        pPanel->DockSize.cx :
        pPanel->MinWidth;

   cy = pPanel->DockSize.cy > 0 ?
        pPanel->DockSize.cy :
        pPanel->MinHeight;;

   switch( Site )
   {
      case HB_DOCKSITE_RIGHT:

         SetRect(
            pHidden,
            rc.right - HBDOCK_AUTOHIDE_STRIP,
            rc.top,
            rc.right,
            rc.bottom );

         SetRect(
            pVisible,
            rc.right - cx,
            rc.top,
            rc.right,
            rc.bottom );
         break;

      case HB_DOCKSITE_TOP:

         SetRect(
            pHidden,
            rc.left,
            rc.top,
            rc.right,
            rc.top + HBDOCK_AUTOHIDE_STRIP );

         SetRect(
            pVisible,
            rc.left,
            rc.top,
            rc.right,
            rc.top + cy );
         break;

      case HB_DOCKSITE_BOTTOM:

         SetRect(
            pHidden,
            rc.left,
            rc.bottom - HBDOCK_AUTOHIDE_STRIP,
            rc.right,
            rc.bottom );

         SetRect(
            pVisible,
            rc.left,
            rc.bottom - cy,
            rc.right,
            rc.bottom );
         break;

      case HB_DOCKSITE_LEFT:
      default:

         SetRect(
            pHidden,
            rc.left,
            rc.top,
            rc.left + HBDOCK_AUTOHIDE_STRIP,
            rc.bottom );

         SetRect(
            pVisible,
            rc.left,
            rc.top,
            rc.left + cx,
            rc.bottom );
         break;
   }
}

void hbDockManagerAutoHidePanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_AUTOHIDE * pAutoHide;
   HB_DOCK_SITE Site;

   if( pManager == NULL || pPanel == NULL )
      return;

   if( hbDockManagerFindAutoHide( pManager, pPanel ) != NULL )
      return;

   Site = hbDockPanelGetDockSite( pPanel );

   /*
    * Nota de estabilizacion: AutoHide no tiene sentido para un panel
    * sin un borde claro contra el cual replegarse (CENTER -- un
    * panel tabificado -- o NONE). hbDockManagerCalcAutoHideRects
    * solo maneja LEFT/RIGHT/TOP/BOTTOM en su switch; con CENTER o
    * NONE, pHidden/pVisible quedaban con memoria sin inicializar
    * (nunca se les asignaba nada), y eso corrompia el resto del
    * layout -- confirmado con captura real: dejaba toda la ventana
    * en blanco. Se rechaza de forma segura en vez de proceder con
    * rects invalidos.
    */
   if( Site != HB_DOCKSITE_LEFT &&
       Site != HB_DOCKSITE_RIGHT &&
       Site != HB_DOCKSITE_TOP &&
       Site != HB_DOCKSITE_BOTTOM )
      return;

   hbDockManagerUndockPanel(
      pManager,
      pPanel );

   pAutoHide = ( HB_DOCK_AUTOHIDE * ) calloc(
      1,
      sizeof( HB_DOCK_AUTOHIDE ) );

   if( pAutoHide == NULL )
      return;

   hbDockAutoHideInit(
      pAutoHide,
      pPanel );

   hbDockManagerCalcAutoHideRects(
      pManager,
      pPanel,
      Site,
      &pAutoHide->HiddenRect,
      &pAutoHide->VisibleRect );

   hbDockAutoHideEnable(
      pAutoHide,
      1 );

   hbDockAutoHideCollapse(
      pAutoHide );

   if( pPanel->hWnd != NULL )
      ShowWindow(
         pPanel->hWnd,
         SW_HIDE );

   pPanel->Visible = 0;

   hbDockArrayAdd(
      &pManager->AutoHideManager.Panes,
      pAutoHide );

   hbDockManagerRefreshLayout(
      pManager );
}

void hbDockManagerAutoHideRestore(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_AUTOHIDE * pAutoHide;
   HB_DOCK_SITE Site;
   int i;

   if( pManager == NULL || pPanel == NULL )
      return;

   pAutoHide = hbDockManagerFindAutoHide( pManager, pPanel );

   if( pAutoHide == NULL )
      return;

   for( i = 0; i < pManager->AutoHideManager.Panes.Count; ++i )
   {
      if( hbDockArrayGet(
             &pManager->AutoHideManager.Panes,
             i ) == pAutoHide )
      {
         hbDockArrayRemove(
            &pManager->AutoHideManager.Panes,
            i );
         break;
      }
   }
 
   free( pAutoHide );

   Site = hbDockPanelGetDockSite( pPanel );

   pPanel->Visible = 1;

   if( pPanel->hWnd != NULL )
      ShowWindow(
         pPanel->hWnd,
         SW_SHOW );

   /*
    * Nota de estabilizacion: esta funcion reinsertaba usando
    * pPanel->pContainer -- pero hbDockManagerAutoHidePanel llama a
    * hbDockManagerUndockPanel al entrar en autohide, que (correctamente,
    * desde que se asigna el enlace inverso panel-contenedor) deja
    * pPanel->pContainer en NULL. Reinsertar con un contenedor NULL
    * fallaba en silencio. Se delega en hbDockManagerDockPanel, que
    * ya crea un contenedor nuevo, inserta, asigna el enlace inverso
    * y repinta -- el mismo camino que "Dock()" normal.
    */
   hbDockManagerDockPanel(
      pManager,
      pPanel,
      ( HB_DOCK_GUIDE_TYPE ) Site );
}

void hbDockManagerAutoHideExpand(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_AUTOHIDE * pAutoHide;

   if( pManager == NULL || pPanel == NULL )
      return;

   pAutoHide = hbDockManagerFindAutoHide( pManager, pPanel );

   if( pAutoHide == NULL || pAutoHide->Expanded )
      return;

   pAutoHide->Expanded = 1;

   if( pPanel->hWnd != NULL )
   {
      ShowWindow(
         pPanel->hWnd,
         SW_SHOW );

      BringWindowToTop(
         pPanel->hWnd );
   }

   /* Etapa 11: si el panel tiene animacion habilitada, no saltamos
    * directo a VisibleRect -- arrancamos el deslizamiento y lo
    * registramos en el AnimationManager del manager; el timer real
    * (Etapa 11, hbdockhost.c) lo va llevando de a poco en cada tick.
    * Si Animation esta apagado para este panel, se mantiene el salto
    * instantaneo de siempre (hbDockAutoHideExpand, Etapa 1). */
   if( pAutoHide->Animation )
   {
      pAutoHide->SlideSize = 100;
      pAutoHide->SlidePosition = 0;
      pAutoHide->SlideStep = 20;

      hbDockAutoHideSlideIn(
         pAutoHide );

      hbDockAutoHideAnimationAddPane(
         &pManager->AnimationManager,
         pAutoHide );
   }
   else
   {
      hbDockAutoHideExpand( pAutoHide );

      if( pPanel->hWnd != NULL )
      {
         MoveWindow(
            pPanel->hWnd,
            pPanel->Rect.left,
            pPanel->Rect.top,
            pPanel->Rect.right  - pPanel->Rect.left,
            pPanel->Rect.bottom - pPanel->Rect.top,
            TRUE );
      }
   }
}

void hbDockManagerAutoHideCollapse(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_AUTOHIDE * pAutoHide;

   if( pManager == NULL || pPanel == NULL )
      return;

   pAutoHide = hbDockManagerFindAutoHide( pManager, pPanel );

   if( pAutoHide == NULL || !pAutoHide->Expanded )
      return;

   pAutoHide->Expanded = 0;

   if( pAutoHide->Animation )
   {
      /* Etapa 11: al contrario que Expand, aca NO ocultamos la
       * ventana todavia -- tiene que verse deslizarse hacia afuera.
       * hbDockAutoHideAnimationManagerTick la oculta (SW_HIDE) recien
       * cuando el deslizamiento termina de verdad. */
      pAutoHide->SlideSize = 100;

      if( pAutoHide->SlidePosition <= 0 )
         pAutoHide->SlidePosition = 100;

      pAutoHide->SlideStep = 20;

      hbDockAutoHideSlideOut(
         pAutoHide );

      hbDockAutoHideAnimationAddPane(
         &pManager->AnimationManager,
         pAutoHide );
   }
   else
   {
      hbDockAutoHideCollapse( pAutoHide );

      if( pPanel->hWnd != NULL )
         ShowWindow(
            pPanel->hWnd,
            SW_HIDE );
   }
}

HB_DOCK_PANEL * hbDockManagerAutoHideHitTest(
   HB_DOCK_MANAGER * pManager,
   POINT pt )
{
   int i;

   if( pManager == NULL )
      return NULL;

   for( i = 0; i < pManager->AutoHideManager.Panes.Count; ++i )
   {
      HB_DOCK_AUTOHIDE * pAutoHide =
         ( HB_DOCK_AUTOHIDE * ) hbDockArrayGet(
            &pManager->AutoHideManager.Panes,
            i );

      if( pAutoHide != NULL &&
          PtInRect( &pAutoHide->HiddenRect, pt ) )
         return pAutoHide->Panel;
   }

   return NULL;
}
