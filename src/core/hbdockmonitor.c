#include "hbdockmonitor.h"

BOOL hbDockMonitorGetWorkArea(
   HWND hWnd,
   RECT * pWorkArea )
{
   HMONITOR hMonitor;
   MONITORINFO mi;

   if( pWorkArea == NULL )
      return FALSE;

   hMonitor = MonitorFromWindow(
      hWnd,
      MONITOR_DEFAULTTONEAREST );

   if( hMonitor == NULL )
      return FALSE;

   mi.cbSize = sizeof( MONITORINFO );

   if( !GetMonitorInfo(
            hMonitor,
            &mi ) )
      return FALSE;

   *pWorkArea = mi.rcWork;

   return TRUE;
}

BOOL hbDockMonitorGetWorkAreaAtPoint(
   POINT pt,
   RECT * pWorkArea )
{
   HMONITOR hMonitor;
   MONITORINFO mi;

   if( pWorkArea == NULL )
      return FALSE;

   hMonitor = MonitorFromPoint(
      pt,
      MONITOR_DEFAULTTONEAREST );

   if( hMonitor == NULL )
      return FALSE;

   mi.cbSize = sizeof( MONITORINFO );

   if( !GetMonitorInfo(
            hMonitor,
            &mi ) )
      return FALSE;

   *pWorkArea = mi.rcWork;

   return TRUE;
}

/*
 * Callback de EnumDisplayMonitors: si el rect que estamos buscando
 * (guardado en lParam, como puntero a una estructura de contexto)
 * intersecta este monitor, marcamos "visible" y frenamos la
 * enumeracion devolviendo FALSE.
 */
typedef struct
{
   const RECT * pRect;
   BOOL Visible;

} HB_DOCK_MONITOR_VISIBLE_CTX;

static BOOL CALLBACK hbDockMonitorVisibleProc(
   HMONITOR hMonitor,
   HDC hDC,
   LPRECT pMonRect,
   LPARAM lParam )
{
   HB_DOCK_MONITOR_VISIBLE_CTX * pCtx;
   RECT rcIntersect;

   ( void )( hMonitor );
   ( void )( hDC );

   pCtx = ( HB_DOCK_MONITOR_VISIBLE_CTX * ) lParam;

   if( IntersectRect(
          &rcIntersect,
          pMonRect,
          pCtx->pRect ) )
   {
      pCtx->Visible = TRUE;

      return FALSE;
   }

   return TRUE;
}

BOOL hbDockMonitorRectIsVisible(
   const RECT * pRect )
{
   HB_DOCK_MONITOR_VISIBLE_CTX Ctx;

   if( pRect == NULL )
      return FALSE;

   Ctx.pRect = pRect;
   Ctx.Visible = FALSE;

   EnumDisplayMonitors(
      NULL,
      NULL,
      hbDockMonitorVisibleProc,
      ( LPARAM ) &Ctx );

   return Ctx.Visible;
}

void hbDockMonitorClampRect(
   RECT * pRect,
   const RECT * pWorkArea )
{
   int Width;
   int Height;
   int WorkWidth;
   int WorkHeight;

   if( pRect == NULL || pWorkArea == NULL )
      return;

   Width = pRect->right - pRect->left;
   Height = pRect->bottom - pRect->top;

   WorkWidth = pWorkArea->right - pWorkArea->left;
   WorkHeight = pWorkArea->bottom - pWorkArea->top;

   /* Si la ventana es mas grande que el monitor, se recorta al
    * tamaño del area de trabajo (mejor verla completa y chica que
    * cortada). */
   if( Width > WorkWidth )
      Width = WorkWidth;

   if( Height > WorkHeight )
      Height = WorkHeight;

   /* Correr el rect para que quede adentro por cada borde. */
   if( pRect->left < pWorkArea->left )
   {
      pRect->left = pWorkArea->left;
   }

   if( pRect->top < pWorkArea->top )
   {
      pRect->top = pWorkArea->top;
   }

   if( pRect->left + Width > pWorkArea->right )
   {
      pRect->left = pWorkArea->right - Width;
   }

   if( pRect->top + Height > pWorkArea->bottom )
   {
      pRect->top = pWorkArea->bottom - Height;
   }

   pRect->right = pRect->left + Width;
   pRect->bottom = pRect->top + Height;
}
