#ifndef HBDOCKLAYOUTTRANSACTION_H
#define HBDOCKLAYOUTTRANSACTION_H

#include "hbdockmanagerstate.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_LAYOUT_TRANSACTION
{
   HB_DOCK_MANAGER_STATE * State;

   int Active;

} HB_DOCK_LAYOUT_TRANSACTION;

void hbDockLayoutTransactionBegin(
   HB_DOCK_LAYOUT_TRANSACTION * pTransaction,
   HB_DOCK_MANAGER_STATE * pState );

void hbDockLayoutTransactionCommit(
   HB_DOCK_LAYOUT_TRANSACTION * pTransaction );

void hbDockLayoutTransactionRollback(
   HB_DOCK_LAYOUT_TRANSACTION * pTransaction );

#ifdef __cplusplus
}
#endif

#endif