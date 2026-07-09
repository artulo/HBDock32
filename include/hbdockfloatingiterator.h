#ifndef HBDOCKFLOATINGITERATOR_H
#define HBDOCKFLOATINGITERATOR_H

#include "hbdockfloatingmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   HB_DOCK_FLOATING_MANAGER * pManager;
   int Index;

} HB_DOCK_FLOATING_ITERATOR;

void hbDockFloatingIteratorInit(
   HB_DOCK_FLOATING_ITERATOR * pIterator,
   HB_DOCK_FLOATING_MANAGER * pManager );

HB_DOCK_FLOATING_FRAME * hbDockFloatingIteratorNext(
   HB_DOCK_FLOATING_ITERATOR * pIterator );

void hbDockFloatingIteratorReset(
   HB_DOCK_FLOATING_ITERATOR * pIterator );

#ifdef __cplusplus
}
#endif

#endif