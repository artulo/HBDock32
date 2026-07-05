/*
 * ---------------------------------------------------------------------------
 * HBDock32
 * Harbour Docking Library
 *
 * File......: hbdocktypes.h
 * Compiler..: Borland C++ 5.5 (BCC32)
 * Language..: ANSI C89
 * Platform..: Win32
 *
 * Copyright (c) 2026 Arturo Tamayo Daza
 * License: MIT
 * ---------------------------------------------------------------------------
 */

#ifndef HBDOCK_TYPES_H_
#define HBDOCK_TYPES_H_

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------
 * Basic Types
 *---------------------------------------------------------------------*/

typedef unsigned char   HB_BYTE;
typedef unsigned short  HB_WORD;
typedef unsigned long   HB_DWORD;

typedef int             HB_BOOL;

#ifndef HB_TRUE
#define HB_TRUE  1
#endif

#ifndef HB_FALSE
#define HB_FALSE 0
#endif

typedef void * HB_HANDLE;

/*----------------------------------------------------------------------
 * Rectangle
 *---------------------------------------------------------------------*/

typedef struct _HB_RECT
{
   int Left;
   int Top;
   int Right;
   int Bottom;

} HB_RECT;

/*----------------------------------------------------------------------
 * Point
 *---------------------------------------------------------------------*/

typedef struct _HB_POINT
{
   int X;
   int Y;

} HB_POINT;

/*----------------------------------------------------------------------
 * Size
 *---------------------------------------------------------------------*/

typedef struct _HB_SIZE
{
   int Width;
   int Height;

} HB_SIZE;

/*----------------------------------------------------------------------
 * Dock Position
 *---------------------------------------------------------------------*/

#define HB_DOCK_NONE      0
#define HB_DOCK_LEFT      1
#define HB_DOCK_RIGHT     2
#define HB_DOCK_TOP       3
#define HB_DOCK_BOTTOM    4
#define HB_DOCK_FILL      5
#define HB_DOCK_FLOATING  6

/*----------------------------------------------------------------------
 * Orientation
 *---------------------------------------------------------------------*/

#define HB_ORIENT_HORIZONTAL  0
#define HB_ORIENT_VERTICAL    1

/*----------------------------------------------------------------------
 * Visibility
 *---------------------------------------------------------------------*/

#define HB_VISIBLE   1
#define HB_HIDDEN    0

#ifdef __cplusplus
}
#endif

#endif /* HBDOCK_TYPES_H_ */