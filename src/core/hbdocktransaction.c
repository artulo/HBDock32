#include "hbdocktransaction.h"

BOOL hbDockTransactionBegin(
        HB_DOCK_TRANSACTION * pTx )
{
    if( pTx == NULL )
        return FALSE;

    pTx->State = HB_TX_RUNNING;

    pTx->Level++;

    pTx->Modified = FALSE;

    return TRUE;
}

BOOL hbDockTransactionCommit(
        HB_DOCK_TRANSACTION * pTx )
{
    if( pTx == NULL )
        return FALSE;

    if( pTx->Level )
        pTx->Level--;

    if( pTx->Level == 0 )
        pTx->State = HB_TX_IDLE;

    return TRUE;
}

BOOL hbDockTransactionRollback(
        HB_DOCK_TRANSACTION * pTx )
{
    if( pTx == NULL )
        return FALSE;

    pTx->Modified = FALSE;

    pTx->Level = 0;

    pTx->State = HB_TX_IDLE;

    return TRUE;
}