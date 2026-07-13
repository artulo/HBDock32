#ifndef HBDOCKKERNEL_H
#define HBDOCKKERNEL_H

#include "hbdockmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockKernelInitialize(
        HB_DOCK_MANAGER * pManager );

void hbDockKernelShutdown(
        HB_DOCK_MANAGER * pManager );

BOOL hbDockKernelProcess(
        HB_DOCK_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif