#include "hbdocktreeenum.h"

int hbDockTreeEnum(
   HB_DOCK_NODE * pRoot,
   HB_DOCK_ENUM_PROC pProc,
   void * pData )
{
   if( pRoot == NULL )
      return 1;

   if( pProc != NULL )
   {
      if( !pProc(
            pRoot,
            pData ) )
         return 0;
   }

   if( !hbDockTreeEnum(
         pRoot->First,
         pProc,
         pData ) )
      return 0;

   if( !hbDockTreeEnum(
         pRoot->Second,
         pProc,
         pData ) )
      return 0;

   return 1;
}