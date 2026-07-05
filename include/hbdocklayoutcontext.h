#ifndef HBDOCKLAYOUTCONTEXT_H
#define HBDOCKLAYOUTCONTEXT_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   RECT ClientRect;

   HB_DOCK_NODE * Root;

   int Width;

   int Height;

} HB_DOCK_LAYOUT_CONTEXT;

void hbDockLayoutContextInit(
   HB_DOCK_LAYOUT_CONTEXT * pContext );

void hbDockLayoutContextSetRect(
   HB_DOCK_LAYOUT_CONTEXT * pContext,
   const RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif