#include <windows.h>

#include "hbdockdragpreview.h"

static void hbDockGuideToPreviewRect(
   HB_DOCK_GUIDE_TYPE Guide,
   const RECT * pClient,
   POINT pt,
   RECT * pPreview )
{
   *pPreview = *pClient;

   switch( Guide )
   {
      case HB_GUIDE_LEFT:

         pPreview->right =
            pPreview->left +
            ( pClient->right - pClient->left ) / 2;
         break;

      case HB_GUIDE_RIGHT:

         pPreview->left =
            pPreview->left +
            ( pClient->right - pClient->left ) / 2;
         break;

      case HB_GUIDE_TOP:

         pPreview->bottom =
            pPreview->top +
            ( pClient->bottom - pClient->top ) / 2;
         break;

      case HB_GUIDE_BOTTOM:

         pPreview->top =
            pPreview->top +
            ( pClient->bottom - pClient->top ) / 2;
         break;

      case HB_GUIDE_CENTER:

         /*
          * Nota de estabilizacion (Etapa 19): esto dejaba el rect
          * SIN acotar -- *pPreview = *pClient de la linea de arriba
          * quedaba tal cual, pintando la ventana principal ENTERA de
          * azul (confirmado con captura real). Ademas, hoy CENTER
          * tabifica sobre un panel puntual (el primer leaf del
          * arbol, hbDockFindFirstLeaf en hbdockmanagerdock.c), asi
          * que "toda la ventana" ni siquiera representa bien lo que
          * va a pasar. Se muestra un area modesta centrada en el
          * mouse en su lugar -- menos preciso que resaltar el panel
          * destino real (eso requeriria hit-testing contra el
          * arbol, que esta fuera del alcance de este fix puntual),
          * pero deja de ser enganoso/abrumador.
          */
         SetRect(
            pPreview,
            pt.x - 100,
            pt.y - 75,
            pt.x + 100,
            pt.y + 75 );

         if( pPreview->left < pClient->left )
            OffsetRect( pPreview, pClient->left - pPreview->left, 0 );

         if( pPreview->right > pClient->right )
            OffsetRect( pPreview, pClient->right - pPreview->right, 0 );

         if( pPreview->top < pClient->top )
            OffsetRect( pPreview, 0, pClient->top - pPreview->top );

         if( pPreview->bottom > pClient->bottom )
            OffsetRect( pPreview, 0, pClient->bottom - pPreview->bottom );

         break;

      default:

         SetRectEmpty(
            pPreview );
         break;
   }
}

void hbDockDragPreviewUpdate(
   HB_DOCK_MANAGER * pManager,
   POINT pt )
{
   RECT rcClient;
   RECT rcPreview;
   RECT rcScreen;
   POINT ptTL;
   POINT ptBR;

   HB_DOCK_GUIDE_TYPE Guide;

   if( pManager == NULL )
      return;

   Guide =
      hbDockGuideManagerHitTest(
         &pManager->GuideManager,
         pt );

   if( Guide == HB_GUIDE_NONE )
   {
      hbDockPreviewOverlayHide(
         &pManager->Preview );

      return;
   }

   GetClientRect(
      pManager->hMainWnd,
      &rcClient );

   hbDockGuideToPreviewRect(
      Guide,
      &rcClient,
      pt,
      &rcPreview );

   /*
    * Nota de estabilizacion (Etapa 19): mismo bug de coordenadas que
    * las guias/diamante (ver hbdockguidemanager.c, Etapa 17) -- el
    * overlay es WS_POPUP (necesita coordenadas de PANTALLA para
    * MoveWindow) pero rcPreview esta en coordenadas de CLIENTE de la
    * ventana principal. Se convierte antes de mover la ventana real.
    */
   ptTL.x = rcPreview.left;
   ptTL.y = rcPreview.top;

   ptBR.x = rcPreview.right;
   ptBR.y = rcPreview.bottom;

   ClientToScreen(
      pManager->hMainWnd,
      &ptTL );

   ClientToScreen(
      pManager->hMainWnd,
      &ptBR );

   SetRect(
      &rcScreen,
      ptTL.x,
      ptTL.y,
      ptBR.x,
      ptBR.y );

   hbDockPreviewOverlayShow(
      &pManager->Preview,
      &rcScreen );
}

void hbDockDragPreviewHide(
   HB_DOCK_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   hbDockPreviewOverlayHide(
      &pManager->Preview );
}