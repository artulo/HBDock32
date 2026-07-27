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

typedef unsigned char   HB_DOCK_BYTE;
typedef unsigned short  HB_DOCK_WORD;
typedef unsigned long   HB_DOCK_DWORD;

typedef int             HB_DOCK_BOOL;

#ifndef HB_DOCK_TRUE
#define HB_DOCK_TRUE  1
#endif

#ifndef HB_DOCK_FALSE
#define HB_DOCK_FALSE 0
#endif

typedef void * HB_DOCK_HANDLE;

/*----------------------------------------------------------------------
 * Rectangle
 *---------------------------------------------------------------------*/

typedef struct _HB_DOCK_RECT
{
   int Left;
   int Top;
   int Right;
   int Bottom;

} HB_DOCK_RECT;

/*----------------------------------------------------------------------
 * Point
 *---------------------------------------------------------------------*/

typedef struct _HB_DOCK_POINT
{
   int X;
   int Y;

} HB_DOCK_POINT;

/*----------------------------------------------------------------------
 * Size
 *---------------------------------------------------------------------*/

typedef struct _HB_DOCK_SIZE
{
   int Width;
   int Height;

} HB_DOCK_SIZE;

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

#define HB_DOCK_ORIENT_HORIZONTAL  0
#define HB_DOCK_ORIENT_VERTICAL    1

/*----------------------------------------------------------------------
 * Visibility
 *---------------------------------------------------------------------*/

#define HB_DOCK_VISIBLE_FLAG   1
#define HB_DOCK_HIDDEN_FLAG    0

#ifdef __cplusplus
}
#endif

#endif /* HBDOCK_TYPES_H_ */