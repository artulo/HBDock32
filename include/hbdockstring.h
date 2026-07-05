#ifndef HBDOCKSTRING_H
#define HBDOCKSTRING_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

char * hbDockStrDup(
   const char * pszText );

void hbDockStrCopy(
   char * pszDest,
   const char * pszSrc,
   size_t nSize );

#ifdef __cplusplus
}
#endif

#endif