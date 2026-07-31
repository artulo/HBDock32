#include <windows.h>
#include <windowsx.h>

#include "hbdockautohideexpandcaption.h"
#include "hbdockcaption.h"
#include "hbdockmanagerautohide.h"

#define HBDOCK_AUTOHIDE_OVERLAY_CLASS   TEXT( "HBDockAutoHideOverlay" )

/*
 * Etapa 79: pedido explicito -- rediseno completo del overlay de
 * AutoHide expandido. Las versiones anteriores (Etapa 58-78) usaban
 * una ventana WS_CHILD (hermana de los paneles acoplados) y trataban
 * de forzar su z-order via BringWindowToTop/HWND_TOPMOST -- ninguno
 * de los dos es confiable entre ventanas HIJAS: BringWindowToTop
 * solo reordena entre hermanas directas (no afecta a HIJOS de OTRAS
 * hermanas, como un GET dentro de otro panel), y WS_EX_TOPMOST no
 * tiene comportamiento garantizado en ventanas hijas (esta pensado
 * para ventanas de nivel superior).
 *
 * Esta version usa una ventana WS_POPUP real -- las popup NO son
 * hijas de nadie (aunque tengan "owner"), viven en su PROPIA capa de
 * z-order de nivel superior, por encima de TODAS las ventanas hijas
 * de su owner, de forma nativa y confiable. El contenido real del
 * panel (pPanel->hWnd) se REPARENTA (SetParent) adentro de esta
 * popup mientras esta expandido -- deja de competir por z-order
 * contra sus hermanos acoplados por completo, en vez de intentar
 * "ganarles" el orden.
 */
static HB_DOCK_MANAGER * s_pManager = NULL;
static HB_DOCK_PANEL * s_pPanel = NULL;

static LRESULT CALLBACK hbDockAutoHideOverlayProc(
   HWND hWnd,
   UINT msg,
   WPARAM wParam,
   LPARAM lParam )
{
   switch( msg )
   {
      case WM_ERASEBKGND:
         return 1;

      case WM_PAINT:
      {
         PAINTSTRUCT ps;
         HDC hDC;
         RECT rc;

         hDC =
            BeginPaint(
               hWnd,
               &ps );

         GetClientRect(
            hWnd,
            &rc );

         /*
          * Etapa 79: la popup ahora abarca el rect COMPLETO (caption
          * + contenido) -- el CONTENIDO lo cubre pPanel->hWnd, una
          * ventana hija real, reparentada aca. Este WM_PAINT solo
          * tiene que dibujar la franja de CAPTION (arriba), no el
          * rect completo.
          */
         if( rc.bottom - rc.top > HBDOCK_CAPTION_HEIGHT )
            rc.bottom = rc.top + HBDOCK_CAPTION_HEIGHT;

         if( s_pPanel != NULL )
         {
            HB_DOCK_CAPTION Caption;

            hbDockCaptionInit(
               &Caption,
               s_pPanel );

            hbDockCaptionLayout(
               &Caption,
               &rc );

            hbDockCaptionDraw(
               hDC,
               &Caption );
         }

         EndPaint(
            hWnd,
            &ps );

         return 0;
      }

      case WM_LBUTTONDOWN:
      {
         RECT rc;
         POINT pt;

         pt.x = GET_X_LPARAM( lParam );
         pt.y = GET_Y_LPARAM( lParam );

         GetClientRect(
            hWnd,
            &rc );

         if( rc.bottom - rc.top > HBDOCK_CAPTION_HEIGHT )
            rc.bottom = rc.top + HBDOCK_CAPTION_HEIGHT;

         if( s_pPanel != NULL && s_pManager != NULL )
         {
            HB_DOCK_CAPTION Caption;
            HB_DOCK_PANEL * pPanel;
            HB_DOCK_MANAGER * pManager;

            hbDockCaptionInit(
               &Caption,
               s_pPanel );

            hbDockCaptionLayout(
               &Caption,
               &rc );

            pPanel = s_pPanel;
            pManager = s_pManager;

            if( PtInRect( &Caption.PinRect, pt ) )
            {
               /*
                * Pin -- reactivar de forma PERMANENTE (redockear).
                */
               hbDockAutoHideExpandCaptionHide(
                  pManager );

               hbDockManagerAutoHideRestore(
                  pManager,
                  pPanel );

               return 0;
            }

            if( PtInRect( &Caption.CloseRect, pt ) )
            {
               /*
                * "x" -- solo replegar de nuevo (sigue en autohide).
                */
               hbDockAutoHideExpandCaptionHide(
                  pManager );

               hbDockManagerAutoHideCollapse(
                  pManager,
                  pPanel );

               return 0;
            }
         }

         return 0;
      }
   }

   return DefWindowProc(
      hWnd,
      msg,
      wParam,
      lParam );
}

static BOOL hbDockAutoHideOverlayRegister(
   HINSTANCE hInstance )
{
   static int Registered = 0;

   WNDCLASS wc;

   if( Registered )
      return TRUE;

   ZeroMemory(
      &wc,
      sizeof( wc ) );

   wc.lpfnWndProc = hbDockAutoHideOverlayProc;
   wc.hInstance = hInstance;
   wc.hCursor =
      LoadCursor(
         NULL,
         IDC_ARROW );
   wc.lpszClassName = HBDOCK_AUTOHIDE_OVERLAY_CLASS;

   Registered =
      RegisterClass( &wc );

   return Registered != 0;
}

/*
 * Etapa 79: crea (si hace falta) y muestra la popup, y REPARENTA
 * pPanel->hWnd adentro -- se usa al EMPEZAR a expandir un panel.
 * pRectScreen es el rect COMPLETO (caption + contenido) en
 * coordenadas de PANTALLA (una popup se posiciona en pantalla, no
 * relativo a un padre -- a diferencia de la ventana WS_CHILD de
 * antes).
 */
void hbDockAutoHideExpandCaptionShow(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   const RECT * pRectScreen )
{
   RECT rcContent;

   if( pManager == NULL || pPanel == NULL || pRectScreen == NULL )
      return;

   if( pManager->AutoHideManager.hExpandCaptionWnd == NULL )
   {
      hbDockAutoHideOverlayRegister(
         GetModuleHandle( NULL ) );

      pManager->AutoHideManager.hExpandCaptionWnd =
         CreateWindowEx(
            WS_EX_TOOLWINDOW,
            HBDOCK_AUTOHIDE_OVERLAY_CLASS,
            TEXT( "" ),
            WS_POPUP | WS_CLIPCHILDREN,
            0, 0, 0, 0,
            pManager->hMainWnd,
            NULL,
            GetModuleHandle( NULL ),
            NULL );
   }

   if( pManager->AutoHideManager.hExpandCaptionWnd == NULL )
      return;

   s_pManager = pManager;
   s_pPanel = pPanel;

   /*
    * Reparentar el contenido REAL del panel adentro de la popup --
    * deja de ser hijo de la ventana principal (y de competir por
    * z-order contra sus hermanos acoplados) mientras dure la
    * expansion.
    */
   if( pPanel->hWnd != NULL &&
       GetParent( pPanel->hWnd ) != pManager->AutoHideManager.hExpandCaptionWnd )
      SetParent(
         pPanel->hWnd,
         pManager->AutoHideManager.hExpandCaptionWnd );

   SetWindowPos(
      pManager->AutoHideManager.hExpandCaptionWnd,
      HWND_TOP,
      pRectScreen->left,
      pRectScreen->top,
      pRectScreen->right - pRectScreen->left,
      pRectScreen->bottom - pRectScreen->top,
      SWP_SHOWWINDOW );

   /*
    * El contenido, ya reparentado, se posiciona en coordenadas
    * RELATIVAS A LA POPUP (0,0 en su esquina) -- debajo de la franja
    * de caption.
    */
   rcContent.left = 0;
   rcContent.top = HBDOCK_CAPTION_HEIGHT;
   rcContent.right = pRectScreen->right - pRectScreen->left;
   rcContent.bottom = pRectScreen->bottom - pRectScreen->top;

   if( rcContent.top > rcContent.bottom )
      rcContent.top = rcContent.bottom;

   if( pPanel->hWnd != NULL )
   {
      MoveWindow(
         pPanel->hWnd,
         rcContent.left,
         rcContent.top,
         rcContent.right  - rcContent.left,
         rcContent.bottom - rcContent.top,
         TRUE );

      ShowWindow(
         pPanel->hWnd,
         SW_SHOW );
   }

   InvalidateRect(
      pManager->AutoHideManager.hExpandCaptionWnd,
      NULL,
      TRUE );
}

/*
 * Etapa 79: reposiciona/redimensiona la popup YA MOSTRADA (durante
 * cada tick de la animacion) -- reusa el mismo reacomodo del
 * contenido que Show, sin volver a reparentar (ya esta reparentado).
 */
void hbDockAutoHideOverlayReposition(
   HB_DOCK_MANAGER * pManager,
   const RECT * pRectScreen )
{
   RECT rcContent;

   if( pManager == NULL || pRectScreen == NULL )
      return;

   if( pManager->AutoHideManager.hExpandCaptionWnd == NULL )
      return;

   SetWindowPos(
      pManager->AutoHideManager.hExpandCaptionWnd,
      HWND_TOP,
      pRectScreen->left,
      pRectScreen->top,
      pRectScreen->right - pRectScreen->left,
      pRectScreen->bottom - pRectScreen->top,
      SWP_SHOWWINDOW | SWP_NOACTIVATE );

   rcContent.left = 0;
   rcContent.top = HBDOCK_CAPTION_HEIGHT;
   rcContent.right = pRectScreen->right - pRectScreen->left;
   rcContent.bottom = pRectScreen->bottom - pRectScreen->top;

   if( rcContent.top > rcContent.bottom )
      rcContent.top = rcContent.bottom;

   if( s_pPanel != NULL && s_pPanel->hWnd != NULL )
      MoveWindow(
         s_pPanel->hWnd,
         rcContent.left,
         rcContent.top,
         rcContent.right  - rcContent.left,
         rcContent.bottom - rcContent.top,
         TRUE );

   InvalidateRect(
      pManager->AutoHideManager.hExpandCaptionWnd,
      NULL,
      TRUE );
}

/*
 * Etapa 79: oculta la popup y REPARENTA el contenido de vuelta a la
 * ventana principal -- se usa al colapsar (o al pin/reactivar).
 */
void hbDockAutoHideExpandCaptionHide(
   HB_DOCK_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   if( s_pPanel != NULL && s_pPanel->hWnd != NULL &&
       pManager->hMainWnd != NULL &&
       GetParent( s_pPanel->hWnd ) != pManager->hMainWnd )
   {
      ShowWindow(
         s_pPanel->hWnd,
         SW_HIDE );

      SetParent(
         s_pPanel->hWnd,
         pManager->hMainWnd );
   }

   if( pManager->AutoHideManager.hExpandCaptionWnd != NULL )
      ShowWindow(
         pManager->AutoHideManager.hExpandCaptionWnd,
         SW_HIDE );

   s_pManager = NULL;
   s_pPanel = NULL;
}
