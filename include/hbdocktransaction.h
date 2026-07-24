#ifndef HBDOCKTRANSACTION_H
#define HBDOCKTRANSACTION_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct _HB_DOCK_TRANSACTION
{
   HB_DOCK_LAYOUT_TREE Backup;

   HB_DOCK_LAYOUT_TREE * pTarget;

   BOOL Active;

} HB_DOCK_TRANSACTION;



BOOL hbDockTransactionBegin(
   HB_DOCK_TRANSACTION * pTransaction,
   HB_DOCK_LAYOUT_TREE * pTree );


BOOL hbDockTransactionCommit(
   HB_DOCK_TRANSACTION * pTransaction );


BOOL hbDockTransactionRollback(
   HB_DOCK_TRANSACTION * pTransaction );


void hbDockTransactionDestroy(
   HB_DOCK_TRANSACTION * pTransaction );


#ifdef __cplusplus
}
#endif

#endif