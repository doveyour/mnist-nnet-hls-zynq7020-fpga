# ==============================================================
# File generated on Mon May 10 08:06:07 CST 2021
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
# SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
# IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
# Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
# ==============================================================
add_files -tb ../src/test.cpp -cflags { -Wno-unknown-pragmas}
add_files mnist/src/hls_mnist.cpp
set_part xc7z020clg400-2
create_clock -name default -period 10
