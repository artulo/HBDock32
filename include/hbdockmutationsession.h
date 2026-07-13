#ifndef HBDOCKMUTATIONSESSION_H
#define HBDOCKMUTATIONSESSION_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    HB_DOCK_LAYOUT_TREE * Tree;

    BOOL Active;

    BOOL Modified;

    UINT OperationCount;

} HB_DOCK_MUTATION_SESSION;

BOOL hbDockMutationBegin(
        HB_DOCK_MUTATION_SESSION * pSession,
        HB_DOCK_LAYOUT_TREE * pTree );

BOOL hbDockMutationCommit(
        HB_DOCK_MUTATION_SESSION * pSession );

BOOL hbDockMutationRollback(
        HB_DOCK_MUTATION_SESSION * pSession );

#ifdef __cplusplus
}
#endif

#endif