#include "hbdockmutationsession.h"

BOOL hbDockMutationBegin(
        HB_DOCK_MUTATION_SESSION * pSession,
        HB_DOCK_LAYOUT_TREE * pTree )
{
    ZeroMemory(
        pSession,
        sizeof(*pSession));

    pSession->Tree = pTree;

    pSession->Active = TRUE;

    return TRUE;
}

BOOL hbDockMutationCommit(
        HB_DOCK_MUTATION_SESSION * pSession )
{
    if(!pSession->Active)
        return FALSE;

    hbDockTreeCompact(
        pSession->Tree );

    hbDockTreeOptimize(
        pSession->Tree );

    hbDockTreeValidate(
        pSession->Tree );

    pSession->Active = FALSE;

    return TRUE;
}

BOOL hbDockMutationRollback(
        HB_DOCK_MUTATION_SESSION * pSession )
{
    pSession->Active = FALSE;

    pSession->Modified = FALSE;

    return TRUE;
}

