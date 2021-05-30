// ==============================================================
// File generated on Mon May 10 08:06:06 CST 2021
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XMNIST_NN_PREDICT_H
#define XMNIST_NN_PREDICT_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xmnist_nn_predict_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Crtl_bus_BaseAddress;
} XMnist_nn_predict_Config;
#endif

typedef struct {
    u32 Crtl_bus_BaseAddress;
    u32 IsReady;
} XMnist_nn_predict;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMnist_nn_predict_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMnist_nn_predict_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMnist_nn_predict_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMnist_nn_predict_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XMnist_nn_predict_Initialize(XMnist_nn_predict *InstancePtr, u16 DeviceId);
XMnist_nn_predict_Config* XMnist_nn_predict_LookupConfig(u16 DeviceId);
int XMnist_nn_predict_CfgInitialize(XMnist_nn_predict *InstancePtr, XMnist_nn_predict_Config *ConfigPtr);
#else
int XMnist_nn_predict_Initialize(XMnist_nn_predict *InstancePtr, const char* InstanceName);
int XMnist_nn_predict_Release(XMnist_nn_predict *InstancePtr);
#endif

void XMnist_nn_predict_Start(XMnist_nn_predict *InstancePtr);
u32 XMnist_nn_predict_IsDone(XMnist_nn_predict *InstancePtr);
u32 XMnist_nn_predict_IsIdle(XMnist_nn_predict *InstancePtr);
u32 XMnist_nn_predict_IsReady(XMnist_nn_predict *InstancePtr);
void XMnist_nn_predict_EnableAutoRestart(XMnist_nn_predict *InstancePtr);
void XMnist_nn_predict_DisableAutoRestart(XMnist_nn_predict *InstancePtr);


void XMnist_nn_predict_InterruptGlobalEnable(XMnist_nn_predict *InstancePtr);
void XMnist_nn_predict_InterruptGlobalDisable(XMnist_nn_predict *InstancePtr);
void XMnist_nn_predict_InterruptEnable(XMnist_nn_predict *InstancePtr, u32 Mask);
void XMnist_nn_predict_InterruptDisable(XMnist_nn_predict *InstancePtr, u32 Mask);
void XMnist_nn_predict_InterruptClear(XMnist_nn_predict *InstancePtr, u32 Mask);
u32 XMnist_nn_predict_InterruptGetEnabled(XMnist_nn_predict *InstancePtr);
u32 XMnist_nn_predict_InterruptGetStatus(XMnist_nn_predict *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
