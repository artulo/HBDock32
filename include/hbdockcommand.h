#ifndef HBDOCKCOMMAND_H
#define HBDOCKCOMMAND_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct _HB_DOCK_PANEL HB_DOCK_PANEL;


typedef enum
{
   HB_CMD_NONE = 0,
   HB_CMD_DOCK,
   HB_CMD_FLOAT,
   HB_CMD_AUTOHIDE,
   HB_CMD_SHOW,
   HB_CMD_HIDE,
   HB_CMD_CLOSE,
   HB_CMD_SPLIT,
   HB_CMD_MERGE,
   HB_CMD_TABIFY,
   HB_CMD_RESTORE_LAYOUT

} HB_DOCK_COMMAND_TYPE;



typedef struct _HB_DOCK_COMMAND
{
   HB_DOCK_COMMAND_TYPE Type;

   HB_DOCK_PANEL * pSource;

   HB_DOCK_PANEL * pTarget;

   LPARAM Param;

} HB_DOCK_COMMAND;



#ifdef __cplusplus
}
#endif

#endif