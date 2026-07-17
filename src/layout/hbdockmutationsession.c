#include "hbdockmutationsession.h"
#include "hbdocklayoutnodecreate.h"
#include "hbdocklayoutoptimizer.h"
#include "hbdocklayoutvalidate.h"
#include "hbdocklayoutcompact.h"

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

    hbDockLayoutCompact(
        pSession->Tree );

    hbDockLayoutOptimize(
        pSession->Tree );

    hbDockLayoutValidate(
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

