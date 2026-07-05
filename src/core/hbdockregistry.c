#include <windows.h>

#include "hbdockregistry.h"

BOOL hbDockRegWriteInt(
   HKEY hRoot,
   const char * pszKey,
   const char * pszValue,
   DWORD dwValue )
{
   HKEY hKey;
   LONG lResult;

   lResult = RegCreateKeyEx(
      hRoot,
      pszKey,
      0,
      NULL,
      REG_OPTION_NON_VOLATILE,
      KEY_WRITE,
      NULL,
      &hKey,
      NULL );

   if( lResult != ERROR_SUCCESS )
      return FALSE;

   lResult = RegSetValueEx(
      hKey,
      pszValue,
      0,
      REG_DWORD,
      ( const BYTE * ) &dwValue,
      sizeof( DWORD ) );

   RegCloseKey( hKey );

   return lResult == ERROR_SUCCESS;
}

BOOL hbDockRegReadInt(
   HKEY hRoot,
   const char * pszKey,
   const char * pszValue,
   DWORD * pdwValue )
{
   HKEY hKey;
   DWORD dwType;
   DWORD dwSize;
   LONG lResult;

   dwSize = sizeof( DWORD );

   lResult = RegOpenKeyEx(
      hRoot,
      pszKey,
      0,
      KEY_READ,
      &hKey );

   if( lResult != ERROR_SUCCESS )
      return FALSE;

   lResult = RegQueryValueEx(
      hKey,
      pszValue,
      NULL,
      &dwType,
      ( BYTE * ) pdwValue,
      &dwSize );

   RegCloseKey( hKey );

   return lResult == ERROR_SUCCESS;
}

BOOL hbDockRegWriteString(
   HKEY hRoot,
   const char * pszKey,
   const char * pszValue,
   const char * pszData )
{
   HKEY hKey;
   LONG lResult;

   lResult = RegCreateKeyEx(
      hRoot,
      pszKey,
      0,
      NULL,
      REG_OPTION_NON_VOLATILE,
      KEY_WRITE,
      NULL,
      &hKey,
      NULL );

   if( lResult != ERROR_SUCCESS )
      return FALSE;

   lResult = RegSetValueEx(
      hKey,
      pszValue,
      0,
      REG_SZ,
      ( const BYTE * ) pszData,
      ( DWORD ) ( lstrlen( pszData ) + 1 ) );

   RegCloseKey( hKey );

   return lResult == ERROR_SUCCESS;
}

BOOL hbDockRegReadString(
   HKEY hRoot,
   const char * pszKey,
   const char * pszValue,
   char * pszBuffer,
   DWORD dwSize )
{
   HKEY hKey;
   DWORD dwType;
   LONG lResult;

   lResult = RegOpenKeyEx(
      hRoot,
      pszKey,
      0,
      KEY_READ,
      &hKey );

   if( lResult != ERROR_SUCCESS )
      return FALSE;

   lResult = RegQueryValueEx(
      hKey,
      pszValue,
      NULL,
      &dwType,
      ( BYTE * ) pszBuffer,
      &dwSize );

   RegCloseKey( hKey );

   return lResult == ERROR_SUCCESS;
}