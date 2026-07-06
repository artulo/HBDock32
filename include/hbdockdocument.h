#ifndef HBDOCKDOCUMENT_H
#define HBDOCKDOCUMENT_H

#include <windows.h>

#include "hbdocktabgroup.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_DOCUMENT_AREA
{
   RECT Rect;

   HB_DOCK_TAB_GROUP Tabs;

} HB_DOCK_DOCUMENT_AREA;

void hbDockDocumentInit(
   HB_DOCK_DOCUMENT_AREA * pArea );

void hbDockDocumentSetRect(
   HB_DOCK_DOCUMENT_AREA * pArea,
   const RECT * pRect );

HB_DOCK_PANEL * hbDockDocumentGetActive(
   HB_DOCK_DOCUMENT_AREA * pArea );

#ifdef __cplusplus
}
#endif

#endif