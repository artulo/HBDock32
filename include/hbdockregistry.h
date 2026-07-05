#ifndef HBDOCKREGISTRY_H
#define HBDOCKREGISTRY_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockRegWriteInt(
   HKEY hRoot,
   const char * pszKey,
   const char * pszValue,
   DWORD dwValue );

BOOL hbDockRegReadInt(
   HKEY hRoot,
   const char * pszKey,
   const char * pszValue,
   DWORD * pdwValue );

BOOL hbDockRegWriteString(
   HKEY hRoot,
   const char * pszKey,
   const char * pszValue,
   const char * pszData );

BOOL hbDockRegReadString(
   HKEY hRoot,
   const char * pszKey,
   const char * pszValue,
   char * pszBuffer,
   DWORD dwSize );

#ifdef __cplusplus
}
#endif

#endif