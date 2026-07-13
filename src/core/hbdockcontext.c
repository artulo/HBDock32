#include "hbdockcontext.h"

BOOL hbDockContextInitialize(
        HB_DOCK_CONTEXT * pContext,
        HB_DOCK_MANAGER * pManager )
{
    ZeroMemory(
        pContext,
        sizeof(*pContext));

    pContext->Manager      = pManager;
    pContext->Layout       = &pManager->LayoutTree;
    pContext->Registry     = &pManager->Registry;
    pContext->Queue        = &pManager->CommandQueue;
    pContext->Transaction  = &pManager->Transaction;

    return TRUE;
}

void hbDockContextDone(
        HB_DOCK_CONTEXT * pContext )
{
    ZeroMemory(
        pContext,
        sizeof(*pContext));
}