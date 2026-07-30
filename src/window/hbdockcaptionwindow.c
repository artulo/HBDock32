#include <windows.h>

#include "hbdockcaptionwindow.h"
#include "hbdockcaption.h"
#include "hbdockcontainer.h"
#include "hbdocktabstrip.h"

#define HBDOCK_CAPTIONWND_CLASS   TEXT( "HBDockCaptionWindow" )

static LRESULT CALLBACK hbDockCaptionWindowProc(
   HWND hWnd,
   UINT uMsg,
   WPARAM wParam,
   LPARAM lParam )
{
   switch( uMsg )
   {
      case WM_NCHITTEST:
         /*
          * Click-through: el mouse "atraviesa" esta ventana --
          * Windows sigue buscando hacia atras en el z-order (la
          * ventana principal, justo debajo) para decidir a quien
          * mandarle el mensaje real. Esto es lo que permite que el
          * hit-test de drag (hbdockhost.c) siga funcionando sin
          * ningun cambio, pese a que ahora hay una ventana real
          * tapando visualmente la franja de caption.
          */
         return HTTRANSPARENT;

      case WM_ERASEBKGND:
         return 1;

      case WM_PAINT:
      {
         PAINTSTRUCT ps;
         HDC hDC;
         RECT rc;
         HB_DOCK_CONTAINER * pContainer;

         hDC =
            BeginPaint(
               hWnd,
               &ps );

         GetClientRect(
            hWnd,
            &rc );

         pContainer =
            ( HB_DOCK_CONTAINER * )
            GetWindowLongPtr(
               hWnd,
               GWLP_USERDATA );

         /*
          * Etapa 51: si hay mas de un panel tabificado en este
          * contenedor, se dibuja la tira de pestañas (una por
          * panel, cada una con su propio boton de cerrar) en vez
          * del caption simple de siempre. Con Count <= 1 el
          * comportamiento es IDENTICO al que ya habia.
          */
         if( pContainer != NULL &&
             pContainer->TabGroup.Count > 1 )
         {
            hbDockTabStripDraw(
               hDC,
               &pContainer->TabGroup,
               &rc );
         }
         else
         {
            HB_DOCK_PANEL * pPanel;
            HB_DOCK_CAPTION Caption;

            pPanel =
               ( pContainer != NULL ) ?
                  pContainer->TabGroup.pPanel :
                  NULL;

            hbDockCaptionInit(
               &Caption,
               pPanel );

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
   }

   return DefWindowProc(
      hWnd,
      uMsg,
      wParam,
      lParam );
}

static BOOL hbDockCaptionWindowRegister(
   HINSTANCE hInstance )
{
   static BOOL Registered = FALSE;

   WNDCLASS wc;

   if( Registered )
      return TRUE;

   ZeroMemory(
      &wc,
      sizeof( wc ) );

   wc.lpfnWndProc = hbDockCaptionWindowProc;
   wc.hInstance = hInstance;
   wc.hCursor =
      LoadCursor(
         NULL,
         IDC_ARROW );
   wc.hbrBackground =
      ( HBRUSH ) GetStockObject(
         NULL_BRUSH );
   wc.lpszClassName =
      HBDOCK_CAPTIONWND_CLASS;

   Registered =
      RegisterClass( &wc );

   return Registered != 0;
}

HWND hbDockCaptionWindowCreate(
   HWND hParent )
{
   HINSTANCE hInst;

   if( hParent == NULL )
      return NULL;

   hInst =
      ( HINSTANCE )
      GetWindowLongPtr(
         hParent,
         GWLP_HINSTANCE );

   if( !hbDockCaptionWindowRegister( hInst ) )
      return NULL;

   return CreateWindowEx(
      0,
      HBDOCK_CAPTIONWND_CLASS,
      TEXT( "" ),
      WS_CHILD |
      WS_CLIPSIBLINGS,
      0,
      0,
      0,
      0,
      hParent,
      NULL,
      hInst,
      NULL );
}

void hbDockCaptionWindowDestroy(
   HWND hWnd )
{
   if( hWnd != NULL )
      DestroyWindow(
         hWnd );
}

void hbDockCaptionWindowUpdate(
   HWND hWnd,
   const RECT * pRect,
   HB_DOCK_CONTAINER * pContainer )
{
   HWND hInsertAfter;
   HB_DOCK_PANEL * pPanel;

   if( hWnd == NULL || pRect == NULL )
      return;

   SetWindowLongPtr(
      hWnd,
      GWLP_USERDATA,
      ( LONG_PTR ) pContainer );

   pPanel =
      ( pContainer != NULL ) ?
         pContainer->TabGroup.pPanel :
         NULL;

   /*
    * Etapa 27: antes esto usaba HWND_TOP -- sube la ventana al tope
    * ABSOLUTO del z-order de TODA la ventana principal, incluyendo
    * ventanas ajenas a HBDock32 (como la barra de botones/toolbar de
    * FiveWin). Confirmado con captura real: la toolbar desaparecia,
    * tapada por la caption. Lo unico que hace falta es que la
    * caption quede por ENCIMA de su propio panel (para no ser
    * tapada por el), no por encima de todo -- se usa una posicion
    * RELATIVA (justo arriba de pPanel->hWnd en el z-order) en vez de
    * una absoluta.
    */
   hInsertAfter =
      ( pPanel != NULL && pPanel->hWnd != NULL ) ?
         pPanel->hWnd :
         NULL;

   if( hInsertAfter != NULL )
   {
      SetWindowPos(
         hWnd,
         hInsertAfter,
         pRect->left,
         pRect->top,
         pRect->right - pRect->left,
         pRect->bottom - pRect->top,
         SWP_SHOWWINDOW );
   }
   else
   {
      SetWindowPos(
         hWnd,
         NULL,
         pRect->left,
         pRect->top,
         pRect->right - pRect->left,
         pRect->bottom - pRect->top,
         SWP_SHOWWINDOW |
         SWP_NOZORDER );
   }

   InvalidateRect(
      hWnd,
      NULL,
      TRUE );
}
