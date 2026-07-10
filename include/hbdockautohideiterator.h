#ifndef HBDOCKAUTOHIDEITERATOR_H
#define HBDOCKAUTOHIDEITERATOR_H

#include "hbdockautohidemanager.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   HB_DOCK_AUTOHIDE_MANAGER * pManager;
   int Index;

} HB_DOCK_AUTOHIDE_ITERATOR;

void hbDockAutoHideIteratorInit(
   HB_DOCK_AUTOHIDE_ITERATOR * pIterator,
   HB_DOCK_AUTOHIDE_MANAGER * pManager );

HB_DOCK_AUTOHIDE_PANE *
hbDockAutoHideIteratorNext(
   HB_DOCK_AUTOHIDE_ITERATOR * pIterator );

#ifdef __cplusplus
}
#endif

#endif