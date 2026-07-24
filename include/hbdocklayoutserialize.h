#ifndef HBDOCKLAYOUTSERIALIZE_H
#define HBDOCKLAYOUTSERIALIZE_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*HB_DOCK_LAYOUT_WRITER)(
   void * Cargo,
   const char * Text );

void WriterDouble(
   void * Cargo,
   double Value );

BOOL hbDockLayoutSerialize(
   const HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_WRITER Writer,
   void * Cargo );

#ifdef __cplusplus
}
#endif

#endif