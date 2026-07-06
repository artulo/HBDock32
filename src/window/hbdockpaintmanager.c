#include "hbdockpaintmanager.h"
#include "hbdockrender.h"

static void hbDockPaintNode(
   HDC hDC,
   HB_DOCK_THEME * pTheme,
   HB_DOCK_NODE * pNode )
{
   if( pNode == NULL )
      return;

   if( pNode->Type == HB_DOCK_NODE_LEAF )
   {
      if( pNode->Panel != NULL )
         hbDockRenderPanel(
            hDC,
            pNode->Panel,
            pTheme );

      return;
   }

   hbDockPaintNode(
      hDC,
      pTheme,
      pNode->First );

   hbDockPaintNode(
      hDC,
      pTheme,
      pNode->Second );
}

void hbDockPaintManagerInit(
   HB_DOCK_PAINT_MANAGER * pPaint )
{
   hbDockThemeDefault(
      &pPaint->Theme );
}

void hbDockPaintManagerDraw(
   HDC hDC,
   HB_DOCK_PAINT_MANAGER * pPaint,
   HB_DOCK_NODE * pRoot )
{
   hbDockPaintNode(
      hDC,
      &pPaint->Theme,
      pRoot );
}