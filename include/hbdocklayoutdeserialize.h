#ifndef HBDOCKLAYOUTDESERIALIZE_H
#define HBDOCKLAYOUTDESERIALIZE_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef const char * (*HB_DOCK_LAYOUT_READER)(
   void * Cargo );

BOOL hbDockLayoutDeserialize(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_READER Reader,
   void * Cargo );

#ifdef __cplusplus
}
#endif

#endif