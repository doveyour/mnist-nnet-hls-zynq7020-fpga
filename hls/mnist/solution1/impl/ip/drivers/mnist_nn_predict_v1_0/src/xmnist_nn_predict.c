// ==============================================================
// File generated on Mon May 10 08:06:06 CST 2021
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmnist_nn_predict.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMnist_nn_predict_CfgInitialize(XMnist_nn_predict *InstancePtr, XMnist_nn_predict_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Crtl_bus_BaseAddress = ConfigPtr->Crtl_bus_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMnist_nn_predict_Start(XMnist_nn_predict *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMnist_nn_predict_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_AP_CTRL) & 0x80;
    XMnist_nn_predict_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMnist_nn_predict_IsDone(XMnist_nn_predict *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMnist_nn_predict_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMnist_nn_predict_IsIdle(XMnist_nn_predict *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMnist_nn_predict_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMnist_nn_predict_IsReady(XMnist_nn_predict *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMnist_nn_predict_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMnist_nn_predict_EnableAutoRestart(XMnist_nn_predict *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMnist_nn_predict_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_AP_CTRL, 0x80);
}

void XMnist_nn_predict_DisableAutoRestart(XMnist_nn_predict *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMnist_nn_predict_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_AP_CTRL, 0);
}

void XMnist_nn_predict_InterruptGlobalEnable(XMnist_nn_predict *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMnist_nn_predict_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_GIE, 1);
}

void XMnist_nn_predict_InterruptGlobalDisable(XMnist_nn_predict *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMnist_nn_predict_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_GIE, 0);
}

void XMnist_nn_predict_InterruptEnable(XMnist_nn_predict *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMnist_nn_predict_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_IER);
    XMnist_nn_predict_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_IER, Register | Mask);
}

void XMnist_nn_predict_InterruptDisable(XMnist_nn_predict *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMnist_nn_predict_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_IER);
    XMnist_nn_predict_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_IER, Register & (~Mask));
}

void XMnist_nn_predict_InterruptClear(XMnist_nn_predict *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMnist_nn_predict_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_ISR, Mask);
}

u32 XMnist_nn_predict_InterruptGetEnabled(XMnist_nn_predict *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMnist_nn_predict_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_IER);
}

u32 XMnist_nn_predict_InterruptGetStatus(XMnist_nn_predict *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMnist_nn_predict_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XMNIST_NN_PREDICT_CRTL_BUS_ADDR_ISR);
}

