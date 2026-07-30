#include <windows.h>

#include "hbdockguidemanager.h"
#include "hbdockguidewindow.h"
#include "hbdockguidealpha.h"

#define HBDOCK_GUIDE_SIZE      32
#define HBDOCK_GUIDE_OFFSET    48

static void hbDockGuideInit(
   HB_DOCK_GUIDE * pGuide,
   HB_DOCK_GUIDE_TYPE Type )
{
   ZeroMemory(
      pGuide,
      sizeof( HB_DOCK_GUIDE ) );

   pGuide->Type = Type;

   pGuide->Visible = FALSE;

   pGuide->hWnd = NULL;

   SetRectEmpty(
      &pGuide->Rect );
}

static BOOL hbDockGuideCreateWindow(
   HB_DOCK_GUIDE * pGuide,
   HWND hParent )
{
   pGuide->hWnd =
      hbDockGuideWindowCreate(
         hParent );

   if( pGuide->hWnd == NULL )
      return FALSE;

   /*
    * Etapa 16: hbDockGuideWindowCreate usa WS_EX_LAYERED (necesario
    * para que ShowWindow/MoveWindow no dejen artefactos al superponer
    * la ventana sobre el contenido de abajo) -- pero una ventana
    * layered sin SetLayeredWindowAttributes queda invisible por
    * default en Windows, pese a que su WM_PAINT si dibuja el
    * rectangulo azul correctamente. hbDockGuideSetAlpha ya existia
    * (src/guides/hbdockguidealpha.c) pero no lo llamaba nadie en
    * todo el proyecto.
    */
   hbDockGuideSetAlpha(
      pGuide->hWnd,
      255 );

   return TRUE;
}

static void hbDockGuideDestroyWindow(
   HB_DOCK_GUIDE * pGuide )
{
   if( pGuide->hWnd != NULL )
   {
      hbDockGuideWindowDestroy(
         pGuide->hWnd );

      pGuide->hWnd = NULL;
   }
}

static void hbDockGuideShow(
   HB_DOCK_GUIDE * pGuide )
{
   pGuide->Visible = TRUE;

   hbDockGuideWindowShow(
      pGuide->hWnd );
}

static void hbDockGuideHide(
   HB_DOCK_GUIDE * pGuide )
{
   pGuide->Visible = FALSE;

   hbDockGuideWindowHide(
      pGuide->hWnd );
}

static void hbDockGuideMove(
   HB_DOCK_GUIDE_MANAGER * pManager,
   HB_DOCK_GUIDE * pGuide )
{
   RECT rcScreen;
   POINT ptTL;
   POINT ptBR;

   /*
    * Etapa 17: pGuide->Rect esta en coordenadas de CLIENTE de la
    * ventana principal (mismo sistema que pt, que llega de
    * WM_MOUSEMOVE) -- se necesita ASI para el hit-test (comparado
    * contra un pt tambien en cliente). Pero la ventana real es
    * WS_POPUP (nivel de escritorio, ver hbdockguidewindow.c), que
    * necesita coordenadas de PANTALLA para MoveWindow. Se convierte
    * una copia local, dejando pGuide->Rect intacto.
    */
   ptTL.x = pGuide->Rect.left;
   ptTL.y = pGuide->Rect.top;

   ptBR.x = pGuide->Rect.right;
   ptBR.y = pGuide->Rect.bottom;

   ClientToScreen(
      pManager->hParent,
      &ptTL );

   ClientToScreen(
      pManager->hParent,
      &ptBR );

   SetRect(
      &rcScreen,
      ptTL.x,
      ptTL.y,
      ptBR.x,
      ptBR.y );

   hbDockGuideWindowMove(
      pGuide->hWnd,
      &rcScreen );
}

BOOL hbDockGuideManagerCreate(
   HB_DOCK_GUIDE_MANAGER * pManager,
   HWND hParent )
{
   if( pManager == NULL )
      return FALSE;

   ZeroMemory(
      pManager,
      sizeof( HB_DOCK_GUIDE_MANAGER ) );

   pManager->hParent = hParent;

   hbDockGuideInit( &pManager->Left,   HB_GUIDE_LEFT );
   hbDockGuideInit( &pManager->Right,  HB_GUIDE_RIGHT );
   hbDockGuideInit( &pManager->Top,    HB_GUIDE_TOP );
   hbDockGuideInit( &pManager->Bottom, HB_GUIDE_BOTTOM );
   hbDockGuideInit( &pManager->Center, HB_GUIDE_CENTER );

   if( !hbDockGuideCreateWindow( &pManager->Left, hParent ) ||
       !hbDockGuideCreateWindow( &pManager->Right, hParent ) ||
       !hbDockGuideCreateWindow( &pManager->Top, hParent ) ||
       !hbDockGuideCreateWindow( &pManager->Bottom, hParent ) ||
       !hbDockGuideCreateWindow( &pManager->Center, hParent ) )
   {
      hbDockGuideManagerDestroy(
         pManager );

      return FALSE;
   }

   if( !hbDockDiamondCreate(
            &pManager->Diamond,
            hParent ) )
   {
      hbDockGuideManagerDestroy(
         pManager );

      return FALSE;
   }

   pManager->Visible = FALSE;

   return TRUE;
}

void hbDockGuideManagerDestroy(
   HB_DOCK_GUIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   hbDockGuideDestroyWindow( &pManager->Left );
   hbDockGuideDestroyWindow( &pManager->Right );
   hbDockGuideDestroyWindow( &pManager->Top );
   hbDockGuideDestroyWindow( &pManager->Bottom );
   hbDockGuideDestroyWindow( &pManager->Center );

   hbDockDiamondDestroy(
      &pManager->Diamond );

   pManager->Visible = FALSE;
}

void hbDockGuideManagerShow(
   HB_DOCK_GUIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   pManager->Visible = TRUE;

   hbDockGuideShow( &pManager->Left );
   hbDockGuideShow( &pManager->Right );
   hbDockGuideShow( &pManager->Top );
   hbDockGuideShow( &pManager->Bottom );
   hbDockGuideShow( &pManager->Center );

   hbDockDiamondShow(
      &pManager->Diamond );
}

void hbDockGuideManagerHide(
   HB_DOCK_GUIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   pManager->Visible = FALSE;

   hbDockGuideHide( &pManager->Left );
   hbDockGuideHide( &pManager->Right );
   hbDockGuideHide( &pManager->Top );
   hbDockGuideHide( &pManager->Bottom );
   hbDockGuideHide( &pManager->Center );

   hbDockDiamondHide(
      &pManager->Diamond );
}

void hbDockGuideManagerMove(
   HB_DOCK_GUIDE_MANAGER * pManager,
   POINT pt )
{
   if( pManager == NULL )
      return;

   SetRect(
      &pManager->Center.Rect,
      pt.x - HBDOCK_GUIDE_SIZE / 2,
      pt.y - HBDOCK_GUIDE_SIZE / 2,
      pt.x + HBDOCK_GUIDE_SIZE / 2,
      pt.y + HBDOCK_GUIDE_SIZE / 2 );

   pManager->Left.Rect = pManager->Center.Rect;
   OffsetRect(
      &pManager->Left.Rect,
      -HBDOCK_GUIDE_OFFSET,
      0 );

   pManager->Right.Rect = pManager->Center.Rect;
   OffsetRect(
      &pManager->Right.Rect,
      HBDOCK_GUIDE_OFFSET,
      0 );

   pManager->Top.Rect = pManager->Center.Rect;
   OffsetRect(
      &pManager->Top.Rect,
      0,
      -HBDOCK_GUIDE_OFFSET );

   pManager->Bottom.Rect = pManager->Center.Rect;
   OffsetRect(
      &pManager->Bottom.Rect,
      0,
      HBDOCK_GUIDE_OFFSET );

   hbDockGuideMove( pManager, &pManager->Left );
   hbDockGuideMove( pManager, &pManager->Right );
   hbDockGuideMove( pManager, &pManager->Top );
   hbDockGuideMove( pManager, &pManager->Bottom );
   hbDockGuideMove( pManager, &pManager->Center );

   hbDockGuideManagerMoveDiamond(
      pManager,
      pt );
}

/*
 * Etapa 20: posiciona las 4 guias externas cerca de los bordes de
 * pClient (la ventana principal), UNA VEZ -- no siguen al mouse. En
 * el diseño de referencia (Visual Studio / MFC CDockablePane) estas
 * 4 flechas quedan fijas durante todo el arrastre; solo el diamante
 * central se mueve, y lo hace siguiendo al panel bajo el cursor, no
 * al mouse en si (ver hbDockGuideManagerMoveDiamond).
 */
void hbDockGuideManagerPositionOuter(
   HB_DOCK_GUIDE_MANAGER * pManager,
   const RECT * pClient )
{
   int midX;
   int midY;
   int Margin;

   if( pManager == NULL || pClient == NULL )
      return;

   midX = ( pClient->left + pClient->right ) / 2;
   midY = ( pClient->top + pClient->bottom ) / 2;

   Margin = HBDOCK_GUIDE_OFFSET;

   SetRect(
      &pManager->Left.Rect,
      pClient->left + Margin - HBDOCK_GUIDE_SIZE / 2,
      midY - HBDOCK_GUIDE_SIZE / 2,
      pClient->left + Margin + HBDOCK_GUIDE_SIZE / 2,
      midY + HBDOCK_GUIDE_SIZE / 2 );

   SetRect(
      &pManager->Right.Rect,
      pClient->right - Margin - HBDOCK_GUIDE_SIZE / 2,
      midY - HBDOCK_GUIDE_SIZE / 2,
      pClient->right - Margin + HBDOCK_GUIDE_SIZE / 2,
      midY + HBDOCK_GUIDE_SIZE / 2 );

   SetRect(
      &pManager->Top.Rect,
      midX - HBDOCK_GUIDE_SIZE / 2,
      pClient->top + Margin - HBDOCK_GUIDE_SIZE / 2,
      midX + HBDOCK_GUIDE_SIZE / 2,
      pClient->top + Margin + HBDOCK_GUIDE_SIZE / 2 );

   SetRect(
      &pManager->Bottom.Rect,
      midX - HBDOCK_GUIDE_SIZE / 2,
      pClient->bottom - Margin - HBDOCK_GUIDE_SIZE / 2,
      midX + HBDOCK_GUIDE_SIZE / 2,
      pClient->bottom - Margin + HBDOCK_GUIDE_SIZE / 2 );

   hbDockGuideMove( pManager, &pManager->Left );
   hbDockGuideMove( pManager, &pManager->Right );
   hbDockGuideMove( pManager, &pManager->Top );
   hbDockGuideMove( pManager, &pManager->Bottom );
}

void hbDockGuideManagerMoveDiamond(
   HB_DOCK_GUIDE_MANAGER * pManager,
   POINT ptCenter )
{
   RECT rcScreen;
   POINT ptTL;
   POINT ptBR;

   if( pManager == NULL )
      return;

   hbDockDiamondMove(
      &pManager->Diamond,
      ptCenter );

   ptTL.x = pManager->Diamond.Rect.left;
   ptTL.y = pManager->Diamond.Rect.top;

   ptBR.x = pManager->Diamond.Rect.right;
   ptBR.y = pManager->Diamond.Rect.bottom;

   ClientToScreen(
      pManager->hParent,
      &ptTL );

   ClientToScreen(
      pManager->hParent,
      &ptBR );

   SetRect(
      &rcScreen,
      ptTL.x,
      ptTL.y,
      ptBR.x,
      ptBR.y );

   MoveWindow(
      pManager->Diamond.hWnd,
      rcScreen.left,
      rcScreen.top,
      rcScreen.right - rcScreen.left,
      rcScreen.bottom - rcScreen.top,
      TRUE );
}

HB_DOCK_GUIDE_TYPE hbDockGuideManagerHitTest(
   const HB_DOCK_GUIDE_MANAGER * pManager,
   POINT pt )
{
   BOOL FromDiamond;

   return hbDockGuideManagerHitTestEx(
      pManager,
      pt,
      &FromDiamond );
}

HB_DOCK_GUIDE_TYPE hbDockGuideManagerHitTestEx(
   const HB_DOCK_GUIDE_MANAGER * pManager,
   POINT pt,
   BOOL * pFromDiamond )
{
   HB_DOCK_DIAMOND_BUTTON Button;

   if( pFromDiamond != NULL )
      *pFromDiamond = FALSE;

   if( pManager == NULL )
      return HB_GUIDE_NONE;

   if( !pManager->Visible )
      return HB_GUIDE_NONE;

   Button =
      hbDockDiamondHitTest(
         &pManager->Diamond,
         pt );

   switch( Button )
   {
      case HB_DIAMOND_LEFT:
      case HB_DIAMOND_RIGHT:
      case HB_DIAMOND_TOP:
      case HB_DIAMOND_BOTTOM:
      case HB_DIAMOND_CENTER:

         if( pFromDiamond != NULL )
            *pFromDiamond = TRUE;

         switch( Button )
         {
            case HB_DIAMOND_LEFT:   return HB_GUIDE_LEFT;
            case HB_DIAMOND_RIGHT:  return HB_GUIDE_RIGHT;
            case HB_DIAMOND_TOP:    return HB_GUIDE_TOP;
            case HB_DIAMOND_BOTTOM: return HB_GUIDE_BOTTOM;
            case HB_DIAMOND_CENTER: return HB_GUIDE_CENTER;
            default: break;
         }
         break;

      default:
         break;
   }

   if( PtInRect( &pManager->Left.Rect, pt ) )
      return HB_GUIDE_LEFT;

   if( PtInRect( &pManager->Right.Rect, pt ) )
      return HB_GUIDE_RIGHT;

   if( PtInRect( &pManager->Top.Rect, pt ) )
      return HB_GUIDE_TOP;

   if( PtInRect( &pManager->Bottom.Rect, pt ) )
      return HB_GUIDE_BOTTOM;

   return HB_GUIDE_NONE;
}

BOOL hbDockGuideManagerVisible(
   const HB_DOCK_GUIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return FALSE;

   return pManager->Visible;
}

void hbDockGuideManagerPaint(
   const HB_DOCK_GUIDE_MANAGER * pManager )
{
   ( void )( pManager );
}