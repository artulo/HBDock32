#include "hbdockdocument.h"

void hbDockDocumentInit(
   HB_DOCK_DOCUMENT_AREA * pArea )
{
   if( pArea == NULL )
      return;

   ZeroMemory(
      pArea,
      sizeof( HB_DOCK_DOCUMENT_AREA ) );

   hbDockTabGroupInit(
      &pArea->Tabs );
}

void hbDockDocumentSetRect(
   HB_DOCK_DOCUMENT_AREA * pArea,
   const RECT * pRect )
{
   if( pArea == NULL )
      return;

   if( pRect == NULL )
      return;

   pArea->Rect = *pRect;
}

HB_DOCK_PANEL * hbDockDocumentGetActive(
   HB_DOCK_DOCUMENT_AREA * pArea )
{
   if( pArea == NULL )
      return NULL;

   return hbDockTabGroupGetActive(
      &pArea->Tabs );
}