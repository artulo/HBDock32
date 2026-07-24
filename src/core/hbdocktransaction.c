#include <stdlib.h>

#include "hbdocktransaction.h"

#include "hbdocklayouttree.h"
#include "hbdocklayoutserialize.h"
#include "hbdocklayoutdeserialize.h"

BOOL hbDockTransactionBegin(
   HB_DOCK_TRANSACTION * pTransaction,
   HB_DOCK_LAYOUT_TREE * pTree )
{
   if( pTransaction == NULL )
      return FALSE;

   if( pTree == NULL )
      return FALSE;


   ZeroMemory(
      pTransaction,
      sizeof( HB_DOCK_TRANSACTION ) );


   if( !hbDockLayoutCloneTree(
            pTree,
            &pTransaction->Backup ) )
   {
      return FALSE;
   }


   pTransaction->pTarget =
      pTree;


   pTransaction->Active =
      TRUE;


   return TRUE;
}



BOOL hbDockTransactionCommit(
   HB_DOCK_TRANSACTION * pTransaction )
{
   if( pTransaction == NULL )
      return FALSE;


   if( !pTransaction->Active )
      return FALSE;


   hbDockLayoutDestroyTree(
      &pTransaction->Backup );


   pTransaction->Active =
      FALSE;


   return TRUE;
}



BOOL hbDockTransactionRollback(
   HB_DOCK_TRANSACTION * pTransaction )
{
   HB_DOCK_LAYOUT_TREE Temp;


   if( pTransaction == NULL )
      return FALSE;


   if( !pTransaction->Active )
      return FALSE;


   if( pTransaction->pTarget == NULL )
      return FALSE;



   /*
    * Guardar árbol modificado
    */

   Temp =
      *pTransaction->pTarget;



   /*
    * Restaurar copia original
    */

   *pTransaction->pTarget =
      pTransaction->Backup;



   /*
    * Limpiar árbol descartado
    */

   hbDockLayoutDestroyTree(
      &Temp );



   ZeroMemory(
      &pTransaction->Backup,
      sizeof( HB_DOCK_LAYOUT_TREE ) );


   pTransaction->Active =
      FALSE;


   return TRUE;
}



void hbDockTransactionDestroy(
   HB_DOCK_TRANSACTION * pTransaction )
{
   if( pTransaction == NULL )
      return;


   if( pTransaction->Active )
   {
      hbDockLayoutDestroyTree(
         &pTransaction->Backup );
   }


   ZeroMemory(
      pTransaction,
      sizeof( HB_DOCK_TRANSACTION ) );
}