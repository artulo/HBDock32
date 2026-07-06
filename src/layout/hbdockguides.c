#include "hbdockguides.h"

void hbDockGuidesInit(
   HB_DOCK_GUIDES * pGuides )
{
   if( pGuides == NULL )
      return;

   pGuides->Count = 0;
}

void hbDockGuidesBuild(
   HB_DOCK_GUIDES * pGuides,
   HB_DOCK_NODE * pNode )
{
   if( pGuides == NULL )
      return;

   hbDockGuidesInit(
      pGuides );

   hbDockSiteCalc(
      &pGuides->Guide[ 0 ],
      pNode,
      HB_DOCKSITE_LEFT );

   hbDockSiteCalc(
      &pGuides->Guide[ 1 ],
      pNode,
      HB_DOCKSITE_RIGHT );

   hbDockSiteCalc(
      &pGuides->Guide[ 2 ],
      pNode,
      HB_DOCKSITE_TOP );

   hbDockSiteCalc(
      &pGuides->Guide[ 3 ],
      pNode,
      HB_DOCKSITE_BOTTOM );

   hbDockSiteCalc(
      &pGuides->Guide[ 4 ],
      pNode,
      HB_DOCKSITE_CENTER );

   pGuides->Count = 5;
}

HB_DOCK_SITE hbDockGuidesHitTest(
   HB_DOCK_GUIDES * pGuides,
   POINT pt )
{
   int i;

   if( pGuides == NULL )
      return HB_DOCKSITE_NONE;

   for( i = 0; i < pGuides->Count; ++i )
   {
      if( hbDockSiteHitTest(
             &pGuides->Guide[ i ],
             pt ) )
         return pGuides->Guide[ i ].Site;
   }

   return HB_DOCKSITE_NONE;
}