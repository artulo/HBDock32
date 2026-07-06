#ifndef HBDOCKTREEENUM_H
#define HBDOCKTREEENUM_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int ( *HB_DOCK_ENUM_PROC )
(
   HB_DOCK_NODE * pNode,
   void * pData
);

int hbDockTreeEnum(
   HB_DOCK_NODE * pRoot,
   HB_DOCK_ENUM_PROC pProc,
   void * pData );

#ifdef __cplusplus
}
#endif

#endif