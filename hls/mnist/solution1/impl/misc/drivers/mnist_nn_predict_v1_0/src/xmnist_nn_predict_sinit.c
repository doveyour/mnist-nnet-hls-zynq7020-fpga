// ==============================================================
// File generated on Mon May 10 08:06:06 CST 2021
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xmnist_nn_predict.h"

extern XMnist_nn_predict_Config XMnist_nn_predict_ConfigTable[];

XMnist_nn_predict_Config *XMnist_nn_predict_LookupConfig(u16 DeviceId) {
	XMnist_nn_predict_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMNIST_NN_PREDICT_NUM_INSTANCES; Index++) {
		if (XMnist_nn_predict_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMnist_nn_predict_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMnist_nn_predict_Initialize(XMnist_nn_predict *InstancePtr, u16 DeviceId) {
	XMnist_nn_predict_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMnist_nn_predict_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMnist_nn_predict_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

