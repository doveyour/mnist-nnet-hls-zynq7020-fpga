-makelib xcelium_lib/xilinx_vip -sv \
  "/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
  "/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
  "/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
  "/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
  "/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
  "/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
  "/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_if.sv" \
  "/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/clk_vip_if.sv" \
  "/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/rst_vip_if.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "/home/dy/vivado/Vivado/2018.3/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
  "/home/dy/vivado/Vivado/2018.3/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \
-endlib
-makelib xcelium_lib/xpm \
  "/home/dy/vivado/Vivado/2018.3/data/ip/xpm/xpm_VCOMP.vhd" \
-endlib
-makelib xcelium_lib/axi_infrastructure_v1_1_0 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_vip_v1_1_4 -sv \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/98af/hdl/axi_vip_v1_1_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/processing_system7_vip_v1_0_6 -sv \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_processing_system7_0_0/sim/design_1_processing_system7_0_0.v" \
-endlib
-makelib xcelium_lib/xbip_utils_v3_0_9 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/0da8/hdl/xbip_utils_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/axi_utils_v2_0_5 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec8e/hdl/axi_utils_v2_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xbip_pipe_v3_0_5 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/442e/hdl/xbip_pipe_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xbip_dsp48_wrapper_v3_0_4 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/cdbf/hdl/xbip_dsp48_wrapper_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xbip_dsp48_addsub_v3_0_5 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/a04b/hdl/xbip_dsp48_addsub_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xbip_dsp48_multadd_v3_0_5 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/b226/hdl/xbip_dsp48_multadd_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xbip_bram18k_v3_0_5 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/c08f/hdl/xbip_bram18k_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/mult_gen_v12_0_14 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/6bb5/hdl/mult_gen_v12_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/floating_point_v7_1_7 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/c63e/hdl/floating_point_v7_1_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/verilog/mnist_nn_predict_bias1.v" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/verilog/mnist_nn_predict_bias2.v" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/verilog/mnist_nn_predict_bias3.v" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/verilog/mnist_nn_predict_CRTL_BUS_s_axi.v" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/verilog/mnist_nn_predict_fadd_32ns_32ns_32_4_full_dsp_1.v" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/verilog/mnist_nn_predict_fdiv_32ns_32ns_32_12_1.v" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/verilog/mnist_nn_predict_fexp_32ns_32ns_32_8_full_dsp_1.v" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/verilog/mnist_nn_predict_fmul_32ns_32ns_32_3_max_dsp_1.v" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/verilog/mnist_nn_predict_output1.v" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/verilog/mnist_nn_predict_output2.v" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/verilog/mnist_nn_predict_output3.v" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/verilog/mnist_nn_predict_weight1.v" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/verilog/mnist_nn_predict_weight2.v" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/verilog/mnist_nn_predict_weight3.v" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/verilog/mnist_nn_predict.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/ip/mnist_nn_predict_ap_fmul_1_max_dsp_32.vhd" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/ip/mnist_nn_predict_ap_fadd_2_full_dsp_32.vhd" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/ip/mnist_nn_predict_ap_fexp_6_full_dsp_32.vhd" \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/ip/mnist_nn_predict_ap_fdiv_10_no_dsp_32.vhd" \
  "../../../bd/design_1/ip/design_1_mnist_nn_predict_0_2/sim/design_1_mnist_nn_predict_0_2.vhd" \
-endlib
-makelib xcelium_lib/generic_baseblocks_v2_1_0 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_register_slice_v2_1_18 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/cc23/hdl/axi_register_slice_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/fifo_generator_v13_2_3 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/64f4/simulation/fifo_generator_vlog_beh.v" \
-endlib
-makelib xcelium_lib/fifo_generator_v13_2_3 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/64f4/hdl/fifo_generator_v13_2_rfs.vhd" \
-endlib
-makelib xcelium_lib/fifo_generator_v13_2_3 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/64f4/hdl/fifo_generator_v13_2_rfs.v" \
-endlib
-makelib xcelium_lib/axi_data_fifo_v2_1_17 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/c4fd/hdl/axi_data_fifo_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_crossbar_v2_1_19 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/6c9d/hdl/axi_crossbar_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_xbar_0/sim/design_1_xbar_0.v" \
-endlib
-makelib xcelium_lib/lib_cdc_v1_0_2 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \
-endlib
-makelib xcelium_lib/proc_sys_reset_v5_0_13 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_rst_ps7_0_50M_0/sim/design_1_rst_ps7_0_50M_0.vhd" \
-endlib
-makelib xcelium_lib/blk_mem_gen_v8_4_2 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/37c2/simulation/blk_mem_gen_v8_4.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_mnist_nn_predict_0_bram_0/sim/design_1_mnist_nn_predict_0_bram_0.v" \
  "../../../bd/design_1/ip/design_1_mnist_nn_predict_0_bram_1/sim/design_1_mnist_nn_predict_0_bram_1.v" \
-endlib
-makelib xcelium_lib/blk_mem_gen_v8_3_6 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/2751/simulation/blk_mem_gen_v8_3.v" \
-endlib
-makelib xcelium_lib/axi_bram_ctrl_v4_1_0 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/27fe/hdl/axi_bram_ctrl_v4_1_rfs.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_axi_bram_ctrl_0_1/sim/design_1_axi_bram_ctrl_0_1.vhd" \
  "../../../bd/design_1/ip/design_1_axi_bram_ctrl_0_2/sim/design_1_axi_bram_ctrl_0_2.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/sim/design_1.v" \
-endlib
-makelib xcelium_lib/axi_protocol_converter_v2_1_18 \
  "../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/7a04/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_auto_pc_1/sim/design_1_auto_pc_1.v" \
  "../../../bd/design_1/ip/design_1_auto_pc_0/sim/design_1_auto_pc_0.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  glbl.v
-endlib
