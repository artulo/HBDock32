#include <windows.h>

#include "hbdockdiamondcreate.h"
#include "hbdockguidealpha.h"

#define HBDOCK_DIAMOND_CLASS   TEXT( "HBDockDiamondWindow" )

/*
 * Nota de estabilizacion (Etapa 17): el diamante central (icono de
 * 5 zonas que aparece sobre el panel destino durante un drag, estilo
 * Visual Studio) tenia toda la logica de hit-test y posicionamiento
 * de rects (hbDockDiamondHitTest/Layout/Move) pero:
 *
 * 1) Usaba la clase generica "STATIC" de Windows, sin ningun
 *    WM_PAINT propio -- no dibujaba nada en absoluto.
 * 2) Igual que las guias (ver hbdockguidemanager.c, Etapa 16), tenia
 *    WS_EX_LAYERED sin SetLayeredWindowAttributes -- invisible por
 *    default aunque hubiera algo que pintar.
 *
 * Estos offsets/tamaños son EXACTAMENTE los mismos que usa
 * hbDockDiamondMove (src/diamond/hbdockdiamond.c) para calcular
 * LeftRect/RightRect/TopRect/BottomRect/CenterRect en coordenadas
 * absolutas -- se repiten aca como constantes locales para dibujar
 * las mismas 5 zonas en coordenadas RELATIVAS a la ventana (que
 * siempre se reposiciona/redimensiona para cubrir exactamente la
 * union de esos 5 rects, ver hbDockGuideManagerMove). Si alguna vez
 * se cambian los numeros en hbDockDiamondMove, hay que actualizar
 * estos tambien.
 */
#define HBDOCK_DIAMOND_BTN_SIZE    28
#define HBDOCK_DIAMOND_BTN_HALF    ( HBDOCK_DIAMOND_BTN_SIZE / 2 )
#define HBDOCK_DIAMOND_OFFSET      40
#define HBDOCK_DIAMOND_HALFSPAN    ( HBDOCK_DIAMOND_OFFSET + HBDOCK_DIAMOND_BTN_HALF )
#define HBDOCK_DIAMOND_SPAN        ( HBDOCK_DIAMOND_HALFSPAN * 2 )

static void hbDockDiamondPaintButton(
   HDC hDC,
   int cx,
   int cy )
{
   RECT rc;
   HBRUSH hBrush;

   SetRect(
      &rc,
      cx - HBDOCK_DIAMOND_BTN_HALF,
      cy - HBDOCK_DIAMOND_BTN_HALF,
      cx + HBDOCK_DIAMOND_BTN_HALF,
      cy + HBDOCK_DIAMOND_BTN_HALF );

   hBrush =
      CreateSolidBrush(
         RGB( 0, 120, 215 ) );

   FillRect(
      hDC,
      &rc,
      hBrush );

   DeleteObject(
      hBrush );

   FrameRect(
      hDC,
      &rc,
      ( HBRUSH ) GetStockObject(
         WHITE_BRUSH ) );
}

static LRESULT CALLBACK hbDockDiamondWindowProc(
   HWND hWnd,
   UINT message,
   WPARAM wParam,
   LPARAM lParam )
{
   switch( message )
   {
      case WM_ERASEBKGND:
         return 1;

      case WM_PAINT:
      {
         PAINTSTRUCT ps;
         HDC hDC;
         RECT rc;
         HBRUSH hBrush;
         int cCenter;

         hDC =
            BeginPaint(
               hWnd,
               &ps );

         GetClientRect(
            hWnd,
            &rc );

         /* Fondo del "hub" que conecta las 5 zonas visualmente. */
         hBrush =
            ( HBRUSH ) GetStockObject(
               WHITE_BRUSH );

         FillRect(
            hDC,
            &rc,
            hBrush );

         FrameRect(
            hDC,
            &rc,
            ( HBRUSH ) GetStockObject(
               GRAY_BRUSH ) );

         cCenter = HBDOCK_DIAMOND_HALFSPAN;

         /* Centro */
         hbDockDiamondPaintButton(
            hDC, cCenter, cCenter );

         /* Izquierda / Derecha / Arriba / Abajo */
         hbDockDiamondPaintButton(
            hDC, cCenter - HBDOCK_DIAMOND_OFFSET, cCenter );

         hbDockDiamondPaintButton(
            hDC, cCenter + HBDOCK_DIAMOND_OFFSET, cCenter );

         hbDockDiamondPaintButton(
            hDC, cCenter, cCenter - HBDOCK_DIAMOND_OFFSET );

         hbDockDiamondPaintButton(
            hDC, cCenter, cCenter + HBDOCK_DIAMOND_OFFSET );

         EndPaint(
            hWnd,
            &ps );

         return 0;
      }
   }

   return DefWindowProc(
      hWnd,
      message,
      wParam,
      lParam );
}

static BOOL hbDockDiamondRegister(
   HINSTANCE hInstance )
{
   static BOOL Registered = FALSE;

   WNDCLASS wc;

   if( Registered )
      return TRUE;

   ZeroMemory(
      &wc,
      sizeof( wc ) );

   wc.lpfnWndProc = hbDockDiamondWindowProc;
   wc.hInstance = hInstance;
   wc.hCursor =
      LoadCursor(
         NULL,
         IDC_ARROW );
   wc.hbrBackground =
      ( HBRUSH ) GetStockObject(
         NULL_BRUSH );
   wc.lpszClassName =
      HBDOCK_DIAMOND_CLASS;

   Registered =
      RegisterClass( &wc );

   return Registered != 0;
}

BOOL hbDockDiamondCreate(
   HB_DOCK_DIAMOND * pDiamond,
   HWND hParent )
{
   HINSTANCE hInst;

   if( pDiamond == NULL )
      return FALSE;

   ZeroMemory(
      pDiamond,
      sizeof( HB_DOCK_DIAMOND ) );

   hInst =
      ( HINSTANCE )
      GetWindowLongPtr(
         hParent,
         GWLP_HINSTANCE );

   if( !hbDockDiamondRegister( hInst ) )
      return FALSE;

   pDiamond->hOwner = hParent;

   pDiamond->hWnd =
      CreateWindowEx(
         WS_EX_LAYERED |
         WS_EX_TOOLWINDOW |
         WS_EX_TOPMOST,
         HBDOCK_DIAMOND_CLASS,
         TEXT( "" ),
         WS_POPUP,
         0,
         0,
         HBDOCK_DIAMOND_SPAN,
         HBDOCK_DIAMOND_SPAN,
         hParent,
         NULL,
         hInst,
         NULL );

   if( pDiamond->hWnd == NULL )
      return FALSE;

   /*
    * Ver nota de arriba -- sin esto, WS_EX_LAYERED deja la ventana
    * invisible pese a que WM_PAINT si dibuja las 5 zonas.
    */
   hbDockGuideSetAlpha(
      pDiamond->hWnd,
      255 );

   return TRUE;
}

void hbDockDiamondDestroy(
   HB_DOCK_DIAMOND * pDiamond )
{
   if( pDiamond == NULL )
      return;

   if( pDiamond->hWnd )
      DestroyWindow(
         pDiamond->hWnd );

   pDiamond->hWnd = NULL;
}
