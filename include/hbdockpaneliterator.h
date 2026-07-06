#ifndef HBDOCKPANELITERATOR_H
#define HBDOCKPANELITERATOR_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_PANEL_ITERATOR
{
   HB_DOCK_NODE * Stack[128];
   int Top;

} HB_DOCK_PANEL_ITERATOR;

void hbDockPanelIteratorInit(
   HB_DOCK_PANEL_ITERATOR * pIterator,
   HB_DOCK_NODE * pRoot );

HB_DOCK_PANEL * hbDockPanelIteratorNext(
   HB_DOCK_PANEL_ITERATOR * pIterator );

#ifdef __cplusplus
}
#endif

#endif