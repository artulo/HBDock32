#include "hbdocklayoutengine.h"

void hbDockLayoutEngineInit(
   HB_DOCK_LAYOUT_ENGINE * pEngine )
{
   if( pEngine == NULL )
      return;

   pEngine->Root = NULL;
}

void hbDockLayoutEngineSetRoot(
   HB_DOCK_LAYOUT_ENGINE * pEngine,
   HB_DOCK_NODE * pRoot )
{
   if( pEngine == NULL )
      return;

   pEngine->Root = pRoot;
}

void hbDockLayoutEnginePerform(
   HB_DOCK_LAYOUT_ENGINE * pEngine,
   const RECT * pRect )
{
   if( pEngine == NULL )
      return;

   if( pEngine->Root == NULL )
      return;

   hbDockTreeLayout(
      pEngine->Root,
      pRect );
}