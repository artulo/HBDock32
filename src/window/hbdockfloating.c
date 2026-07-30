#include <windows.h>

#include "hbdockfloating.h"
#include "hbdockpanel.h"
#include "hbdockmanagerfloat.h"

#define HBDOCK_FLOAT_CLASS "HBDockFloating"

/*
 * Etapa 47: mensaje propio para diferir el fin del drag-a-diamantes
 * -- ver WM_EXITSIZEMOVE mas abajo. hbDockManagerFloatDragEnd puede
 * terminar destruyendo esta misma ventana (si se redockea) -- hacerlo
 * mientras todavia se esta procesando WM_EXITSIZEMOVE (parte del loop
 * modal interno de Windows para mover/redimensionar) es arriesgado;
 * se difiere para que corra recien cuando ese loop ya termino de
 * desenrollarse.
 */
#define HBDOCK_WM_DEFERRED_DRAGEND ( WM_APP + 0x486 )

/*
 * Nota de estabilizacion (Etapa 9): esta ventana se creaba pero
 * quedaba vacia -- titulo en blanco (""), y el hWnd real del panel
 * (pPanel->hWnd) nunca se reparentaba adentro ni se movia con ella.
 * Flotar un panel mostraba una ventanita gris sin nada dentro. Se
 * corrige: WM_CREATE reparenta el panel como hijo y le pone el
 * titulo real; WM_SIZE lo estira para llenar el cliente; WM_DESTROY
 * lo devuelve a NULL como padre antes de que la ventana desaparezca
 * (si el panel se vuelve a acoplar despues, hbDockPanelSetParent lo
 * reparenta a donde corresponda).
 *
 * Nota de estabilizacion (Etapa 41): cerrar el flotante (la "x")
 * antes solo lo ocultaba (ShowWindow SW_HIDE) -- Windows no siempre
 * devuelve la activacion al owner de forma confiable al ocultar un
 * WS_POPUP owned que tenia el foco (confirmado con diagnostico real:
 * ni SetForegroundWindow sincronico ni diferido via PostMessage
 * lograban revertirlo -- la app entera quedaba sin ninguna ventana
 * activa hasta que el usuario volvia a interactuar). Ahora WM_CLOSE
 * destruye la ventana de verdad -- una ventana REALMENTE destruida
 * no puede retener el foco, Windows esta obligado a transferirlo
 * correctamente como parte de su manejo estandar de destruccion de
 * una ventana owned. WM_DESTROY hace la limpieza: reparenta el panel
 * de vuelta al owner, lo oculta, y limpia pPanel->pFloating/Floating
 * para que la proxima vez que se flote este panel,
 * hbDockManagerFloatPanel lo cree todo de cero correctamente.
 */

static LRESULT CALLBACK hbDockFloatingProc(
   HWND hWnd,
   UINT msg,
   WPARAM wParam,
   LPARAM lParam )
{
   switch( msg )
   {
      case WM_ERASEBKGND:
         return 1;

      case WM_ENTERSIZEMOVE:
      {
         HB_DOCK_FLOATING * pFloating;
         POINT pt;

         pFloating = ( HB_DOCK_FLOATING * )
            GetWindowLongPtr( hWnd, GWLP_USERDATA );

         if( pFloating != NULL && pFloating->Panel != NULL )
         {
            GetCursorPos( &pt );

            hbDockManagerFloatDragBegin(
               pFloating->pManager,
               pFloating->Panel,
               pt );
         }

         return DefWindowProc( hWnd, msg, wParam, lParam );
      }

      case WM_MOVING:
      {
         HB_DOCK_FLOATING * pFloating;
         POINT pt;

         pFloating = ( HB_DOCK_FLOATING * )
            GetWindowLongPtr( hWnd, GWLP_USERDATA );

         if( pFloating != NULL )
         {
            GetCursorPos( &pt );

            hbDockManagerFloatDragMove(
               pFloating->pManager,
               pt );
         }

         return DefWindowProc( hWnd, msg, wParam, lParam );
      }

      case WM_EXITSIZEMOVE:
      {
         HB_DOCK_FLOATING * pFloating;
         POINT pt;

         pFloating = ( HB_DOCK_FLOATING * )
            GetWindowLongPtr( hWnd, GWLP_USERDATA );

         if( pFloating != NULL )
         {
            GetCursorPos( &pt );

            /*
             * Diferido -- ver el define de HBDOCK_WM_DEFERRED_DRAGEND
             * mas arriba. (short) trunca/preserva el signo igual que
             * las macros GET_X_LPARAM/GET_Y_LPARAM que usa el resto
             * del proyecto para coordenadas de mouse -- correcto para
             * el rango real de coordenadas de pantalla, incluso con
             * monitores a la izquierda/arriba del principal (valores
             * negativos).
             */
            PostMessage(
               hWnd,
               HBDOCK_WM_DEFERRED_DRAGEND,
               ( WPARAM ) ( short ) pt.x,
               ( LPARAM ) ( short ) pt.y );
         }

         return DefWindowProc( hWnd, msg, wParam, lParam );
      }

      case HBDOCK_WM_DEFERRED_DRAGEND:
      {
         HB_DOCK_FLOATING * pFloating;
         POINT pt;

         pFloating = ( HB_DOCK_FLOATING * )
            GetWindowLongPtr( hWnd, GWLP_USERDATA );

         pt.x = ( short ) wParam;
         pt.y = ( short ) lParam;

         if( pFloating != NULL )
            hbDockManagerFloatDragEnd(
               pFloating->pManager,
               pt );

         return 0;
      }

      case WM_SIZE:
      {
         HB_DOCK_FLOATING * pFloating;
         RECT rc;

         pFloating = ( HB_DOCK_FLOATING * )
            GetWindowLongPtr( hWnd, GWLP_USERDATA );

         if( pFloating != NULL &&
             pFloating->Panel != NULL &&
             pFloating->Panel->hWnd != NULL )
         {
            GetClientRect(
               hWnd,
               &rc );

            MoveWindow(
               pFloating->Panel->hWnd,
               rc.left,
               rc.top,
               rc.right - rc.left,
               rc.bottom - rc.top,
               TRUE );
         }

         return 0;
      }

      case WM_CLOSE:
         DestroyWindow(
            hWnd );
         return 0;

      case WM_DESTROY:
      {
         HB_DOCK_FLOATING * pFloating;
         HWND hOwner;
         void * pManagerVoid;

         pFloating = ( HB_DOCK_FLOATING * )
            GetWindowLongPtr( hWnd, GWLP_USERDATA );

         hOwner = GetWindow( hWnd, GW_OWNER );

         pManagerVoid = ( pFloating != NULL ) ? pFloating->pManager : NULL;

         if( pFloating != NULL )
         {
            if( pFloating->Panel != NULL )
            {
               if( pFloating->Panel->hWnd != NULL )
               {
                  ShowWindow(
                     pFloating->Panel->hWnd,
                     SW_HIDE );

                  SetParent(
                     pFloating->Panel->hWnd,
                     hOwner );
               }

               pFloating->Panel->pFloating = NULL;
               pFloating->Panel->Floating = FALSE;
            }

            LocalFree(
               pFloating );
         }

         if( hOwner != NULL )
         {
            SetForegroundWindow(
               hOwner );

            SetActiveWindow(
               hOwner );
         }

         /*
          * Etapa 42: aca (no antes) -- despues de EnableWindow(TRUE)
          * volveria a quedar habilitada la ventana ANTES de que
          * SetForegroundWindow/SetActiveWindow terminen de asentar
          * la reactivacion; el orden actual no importa realmente
          * para eso (son independientes), pero se deja aca al final
          * por prolijidad, junto a la limpieza final del flotante.
          */
         hbDockManagerFloatClosed(
            pManagerVoid );

         return 0;
      }
   }

   return DefWindowProc(
      hWnd,
      msg,
      wParam,
      lParam );
}

static BOOL hbDockFloatingRegister(
   HINSTANCE hInstance )
{
   static int Registered = 0;

   WNDCLASS wc;

   if( Registered )
      return TRUE;

   ZeroMemory(
      &wc,
      sizeof( wc ) );

   wc.lpfnWndProc = hbDockFloatingProc;
   wc.hInstance = hInstance;
   wc.hCursor = LoadCursor(
      NULL,
      IDC_ARROW );
   wc.hbrBackground =
      ( HBRUSH ) ( COLOR_BTNFACE + 1 );
   wc.lpszClassName =
      HBDOCK_FLOAT_CLASS;

   Registered =
      RegisterClass( &wc );

   return Registered != 0;
}

BOOL hbDockFloatingCreate(
   HB_DOCK_FLOATING * pFloating,
   HINSTANCE hInstance,
   HB_DOCK_PANEL * pPanel,
   HWND hOwnerWnd )
{
   LPCTSTR pszCaption;

   if( pFloating == NULL )
      return FALSE;

   if( !hbDockFloatingRegister(
         hInstance ) )
      return FALSE;

   pszCaption =
      ( pPanel != NULL ) ? pPanel->Caption : "";

   /*
    * Nota de estabilizacion: el parametro de ventana "padre" de
    * CreateWindowEx, para una ventana WS_POPUP, es en realidad el
    * OWNER -- sin el, esta ventana flotante no tiene ninguna
    * relacion con la ventana principal, y puede terminar tapada
    * detras de ella con solo hacer click en la principal (Windows
    * no tiene motivo para mantenerla al frente si no sabe que le
    * "pertenece"). Confirmado con captura real: la ventana flotante
    * parecia "desaparecer" al clickear, pero seguia abierta, solo
    * que detras de la ventana principal.
    */
   pFloating->hWnd =
      CreateWindowEx(
         WS_EX_TOOLWINDOW,
         HBDOCK_FLOAT_CLASS,
         pszCaption,
         WS_POPUP |
         WS_CAPTION |
         WS_THICKFRAME |
         WS_SYSMENU,
         CW_USEDEFAULT,
         CW_USEDEFAULT,
         300,
         300,
         hOwnerWnd,
         NULL,
         hInstance,
         NULL );

   pFloating->Panel = pPanel;
   pFloating->Active = 0;

   if( pFloating->hWnd == NULL )
      return FALSE;

   SetWindowLongPtr(
      pFloating->hWnd,
      GWLP_USERDATA,
      ( LONG_PTR ) pFloating );

   if( pPanel != NULL && pPanel->hWnd != NULL )
   {
      SetParent(
         pPanel->hWnd,
         pFloating->hWnd );

      ShowWindow(
         pPanel->hWnd,
         SW_SHOW );
   }

   return TRUE;
}

void hbDockFloatingDestroy(
   HB_DOCK_FLOATING * pFloating )
{
   if( pFloating == NULL )
      return;

   if( pFloating->hWnd != NULL )
      DestroyWindow(
         pFloating->hWnd );

   /*
    * Etapa 46 (fix): NO tocar pFloating despues de esto. DestroyWindow
    * dispara WM_DESTROY de forma SINCRONICA -- y desde la Etapa 41,
    * ese handler hace LocalFree(pFloating) como parte de su limpieza
    * normal. Escribir pFloating->hWnd = NULL aca (como se hacia antes)
    * es un use-after-free -- esta funcion no tenia llamadores activos
    * hasta ahora, por eso nunca se manifesto.
    */
}

void hbDockFloatingShow(
   HB_DOCK_FLOATING * pFloating,
   int Show )
{
   if( pFloating == NULL )
      return;

   if( pFloating->hWnd == NULL )
      return;

   ShowWindow(
      pFloating->hWnd,
      Show ? SW_SHOW : SW_HIDE );

   pFloating->Active = Show;
}

void hbDockFloatingMove(
   HB_DOCK_FLOATING * pFloating,
   const RECT * pRect )
{
   if( pFloating == NULL )
      return;

   if( pFloating->hWnd == NULL )
      return;

   MoveWindow(
      pFloating->hWnd,
      pRect->left,
      pRect->top,
      pRect->right - pRect->left,
      pRect->bottom - pRect->top,
      TRUE );

   pFloating->RestoreRect = *pRect;
}
