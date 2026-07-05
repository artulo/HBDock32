#include <stdlib.h>
#include <string.h>

#include "hbdockstring.h"

char * hbDockStrDup(
   const char * pszText )
{
   char * pszCopy;
   size_t nLen;

   if( pszText == NULL )
      return NULL;

   nLen = strlen( pszText );

   pszCopy = ( char * ) malloc(
      nLen + 1 );

   if( pszCopy == NULL )
      return NULL;

   memcpy(
      pszCopy,
      pszText,
      nLen + 1 );

   return pszCopy;
}

void hbDockStrCopy(
   char * pszDest,
   const char * pszSrc,
   size_t nSize )
{
   if( pszDest == NULL || nSize == 0 )
      return;

   if( pszSrc == NULL )
   {
      pszDest[ 0 ] = '\0';
      return;
   }

   strncpy(
      pszDest,
      pszSrc,
      nSize - 1 );

   pszDest[ nSize - 1 ] = '\0';
}