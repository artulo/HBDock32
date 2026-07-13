#ifndef HBDOCKTRANSACTION_H
#define HBDOCKTRANSACTION_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    HB_TX_IDLE = 0,
    HB_TX_RUNNING,
    HB_TX_COMMIT,
    HB_TX_ROLLBACK

} HB_DOCK_TX_STATE;

typedef struct
{
    HB_DOCK_TX_STATE State;

    UINT Level;

    BOOL Modified;

} HB_DOCK_TRANSACTION;

BOOL hbDockTransactionBegin(
        HB_DOCK_TRANSACTION * pTx );

BOOL hbDockTransactionCommit(
        HB_DOCK_TRANSACTION * pTx );

BOOL hbDockTransactionRollback(
        HB_DOCK_TRANSACTION * pTx );

#ifdef __cplusplus
}
#endif

#endif