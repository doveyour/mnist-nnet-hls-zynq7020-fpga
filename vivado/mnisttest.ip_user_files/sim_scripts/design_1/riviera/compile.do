vlib work
vlib riviera

vlib riviera/xilinx_vip
vlib riviera/xil_defaultlib
vlib riviera/xpm
vlib riviera/axi_infrastructure_v1_1_0
vlib riviera/axi_vip_v1_1_4
vlib riviera/processing_system7_vip_v1_0_6
vlib riviera/xbip_utils_v3_0_9
vlib riviera/axi_utils_v2_0_5
vlib riviera/xbip_pipe_v3_0_5
vlib riviera/xbip_dsp48_wrapper_v3_0_4
vlib riviera/xbip_dsp48_addsub_v3_0_5
vlib riviera/xbip_dsp48_multadd_v3_0_5
vlib riviera/xbip_bram18k_v3_0_5
vlib riviera/mult_gen_v12_0_14
vlib riviera/floating_point_v7_1_7
vlib riviera/generic_baseblocks_v2_1_0
vlib riviera/axi_register_slice_v2_1_18
vlib riviera/fifo_generator_v13_2_3
vlib riviera/axi_data_fifo_v2_1_17
vlib riviera/axi_crossbar_v2_1_19
vlib riviera/lib_cdc_v1_0_2
vlib riviera/proc_sys_reset_v5_0_13
vlib riviera/blk_mem_gen_v8_4_2
vlib riviera/blk_mem_gen_v8_3_6
vlib riviera/axi_bram_ctrl_v4_1_0
vlib riviera/axi_protocol_converter_v2_1_18

vmap xilinx_vip riviera/xilinx_vip
vmap xil_defaultlib riviera/xil_defaultlib
vmap xpm riviera/xpm
vmap axi_infrastructure_v1_1_0 riviera/axi_infrastructure_v1_1_0
vmap axi_vip_v1_1_4 riviera/axi_vip_v1_1_4
vmap processing_system7_vip_v1_0_6 riviera/processing_system7_vip_v1_0_6
vmap xbip_utils_v3_0_9 riviera/xbip_utils_v3_0_9
vmap axi_utils_v2_0_5 riviera/axi_utils_v2_0_5
vmap xbip_pipe_v3_0_5 riviera/xbip_pipe_v3_0_5
vmap xbip_dsp48_wrapper_v3_0_4 riviera/xbip_dsp48_wrapper_v3_0_4
vmap xbip_dsp48_addsub_v3_0_5 riviera/xbip_dsp48_addsub_v3_0_5
vmap xbip_dsp48_multadd_v3_0_5 riviera/xbip_dsp48_multadd_v3_0_5
vmap xbip_bram18k_v3_0_5 riviera/xbip_bram18k_v3_0_5
vmap mult_gen_v12_0_14 riviera/mult_gen_v12_0_14
vmap floating_point_v7_1_7 riviera/floating_point_v7_1_7
vmap generic_baseblocks_v2_1_0 riviera/generic_baseblocks_v2_1_0
vmap axi_register_slice_v2_1_18 riviera/axi_register_slice_v2_1_18
vmap fifo_generator_v13_2_3 riviera/fifo_generator_v13_2_3
vmap axi_data_fifo_v2_1_17 riviera/axi_data_fifo_v2_1_17
vmap axi_crossbar_v2_1_19 riviera/axi_crossbar_v2_1_19
vmap lib_cdc_v1_0_2 riviera/lib_cdc_v1_0_2
vmap proc_sys_reset_v5_0_13 riviera/proc_sys_reset_v5_0_13
vmap blk_mem_gen_v8_4_2 riviera/blk_mem_gen_v8_4_2
vmap blk_mem_gen_v8_3_6 riviera/blk_mem_gen_v8_3_6
vmap axi_bram_ctrl_v4_1_0 riviera/axi_bram_ctrl_v4_1_0
vmap axi_protocol_converter_v2_1_18 riviera/axi_protocol_converter_v2_1_18

vlog -work xilinx_vip  -sv2k12 "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_if.sv" \
"/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/clk_vip_if.sv" \
"/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xil_defaultlib  -sv2k12 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"/home/dy/vivado/Vivado/2018.3/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"/home/dy/vivado/Vivado/2018.3/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \

vcom -work xpm -93 \
"/home/dy/vivado/Vivado/2018.3/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work axi_infrastructure_v1_1_0  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work axi_vip_v1_1_4  -sv2k12 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/98af/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work processing_system7_vip_v1_0_6  -sv2k12 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_processing_system7_0_0/sim/design_1_processing_system7_0_0.v" \

vcom -work xbip_utils_v3_0_9 -93 \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/0da8/hdl/xbip_utils_v3_0_vh_rfs.vhd" \

vcom -work axi_utils_v2_0_5 -93 \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec8e/hdl/axi_utils_v2_0_vh_rfs.vhd" \

vcom -work xbip_pipe_v3_0_5 -93 \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/442e/hdl/xbip_pipe_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_wrapper_v3_0_4 -93 \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/cdbf/hdl/xbip_dsp48_wrapper_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_addsub_v3_0_5 -93 \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/a04b/hdl/xbip_dsp48_addsub_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_multadd_v3_0_5 -93 \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/b226/hdl/xbip_dsp48_multadd_v3_0_vh_rfs.vhd" \

vcom -work xbip_bram18k_v3_0_5 -93 \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/c08f/hdl/xbip_bram18k_v3_0_vh_rfs.vhd" \

vcom -work mult_gen_v12_0_14 -93 \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/6bb5/hdl/mult_gen_v12_0_vh_rfs.vhd" \

vcom -work floating_point_v7_1_7 -93 \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/c63e/hdl/floating_point_v7_1_vh_rfs.vhd" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
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

vcom -work xil_defaultlib -93 \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/ip/mnist_nn_predict_ap_fmul_1_max_dsp_32.vhd" \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/ip/mnist_nn_predict_ap_fadd_2_full_dsp_32.vhd" \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/ip/mnist_nn_predict_ap_fexp_6_full_dsp_32.vhd" \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/12b6/hdl/ip/mnist_nn_predict_ap_fdiv_10_no_dsp_32.vhd" \
"../../../bd/design_1/ip/design_1_mnist_nn_predict_0_2/sim/design_1_mnist_nn_predict_0_2.vhd" \

vlog -work generic_baseblocks_v2_1_0  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \

vlog -work axi_register_slice_v2_1_18  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/cc23/hdl/axi_register_slice_v2_1_vl_rfs.v" \

vlog -work fifo_generator_v13_2_3  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/64f4/simulation/fifo_generator_vlog_beh.v" \

vcom -work fifo_generator_v13_2_3 -93 \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/64f4/hdl/fifo_generator_v13_2_rfs.vhd" \

vlog -work fifo_generator_v13_2_3  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/64f4/hdl/fifo_generator_v13_2_rfs.v" \

vlog -work axi_data_fifo_v2_1_17  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/c4fd/hdl/axi_data_fifo_v2_1_vl_rfs.v" \

vlog -work axi_crossbar_v2_1_19  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/6c9d/hdl/axi_crossbar_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_xbar_0/sim/design_1_xbar_0.v" \

vcom -work lib_cdc_v1_0_2 -93 \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \

vcom -work proc_sys_reset_v5_0_13 -93 \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \

vcom -work xil_defaultlib -93 \
"../../../bd/design_1/ip/design_1_rst_ps7_0_50M_0/sim/design_1_rst_ps7_0_50M_0.vhd" \

vlog -work blk_mem_gen_v8_4_2  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/37c2/simulation/blk_mem_gen_v8_4.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_mnist_nn_predict_0_bram_0/sim/design_1_mnist_nn_predict_0_bram_0.v" \
"../../../bd/design_1/ip/design_1_mnist_nn_predict_0_bram_1/sim/design_1_mnist_nn_predict_0_bram_1.v" \

vlog -work blk_mem_gen_v8_3_6  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/2751/simulation/blk_mem_gen_v8_3.v" \

vcom -work axi_bram_ctrl_v4_1_0 -93 \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/27fe/hdl/axi_bram_ctrl_v4_1_rfs.vhd" \

vcom -work xil_defaultlib -93 \
"../../../bd/design_1/ip/design_1_axi_bram_ctrl_0_1/sim/design_1_axi_bram_ctrl_0_1.vhd" \
"../../../bd/design_1/ip/design_1_axi_bram_ctrl_0_2/sim/design_1_axi_bram_ctrl_0_2.vhd" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../bd/design_1/sim/design_1.v" \

vlog -work axi_protocol_converter_v2_1_18  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/7a04/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ipshared/70cf/hdl" "+incdir+../../../../mnisttest.srcs/sources_1/bd/design_1/ip/design_1_processing_system7_0_0" "+incdir+/home/dy/vivado/Vivado/2018.3/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_auto_pc_1/sim/design_1_auto_pc_1.v" \
"../../../bd/design_1/ip/design_1_auto_pc_0/sim/design_1_auto_pc_0.v" \

vlog -work xil_defaultlib \
"glbl.v"

