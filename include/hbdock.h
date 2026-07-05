/*
 * ---------------------------------------------------------------------------
 * HBDock32
 *
 * Main Public Header
 *
 * Compiler : Borland C++ 5.5
 * Harbour  : 3.2 Official
 * Language : ANSI C89
 *
 * ---------------------------------------------------------------------------
 */

#ifndef HBDOCK_H_
#define HBDOCK_H_

#include <windows.h>

#include "hbdocktypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------
 Version
---------------------------------------------------------------*/

#define HBDOCK_VERSION_MAJOR     0
#define HBDOCK_VERSION_MINOR     1
#define HBDOCK_VERSION_BUILD     0

/*---------------------------------------------------------------
 Export
---------------------------------------------------------------*/

#ifndef HBDOCK_API
#define HBDOCK_API
#endif

/*---------------------------------------------------------------
 Initialization
---------------------------------------------------------------*/

HBDOCK_API HB_BOOL hbDockInitialize( void );

HBDOCK_API void hbDockExit( void );

/*---------------------------------------------------------------
 Version
---------------------------------------------------------------*/

HBDOCK_API HB_DWORD hbDockVersion( void );

/*---------------------------------------------------------------
 Information
---------------------------------------------------------------*/

HBDOCK_API const char * hbDockVersionString( void );

#ifdef __cplusplus
}
#endif

#endif