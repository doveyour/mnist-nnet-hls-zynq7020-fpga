// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.3
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _mnist_nn_predict_HH_
#define _mnist_nn_predict_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "mnist_nn_predict_fadd_32ns_32ns_32_4_full_dsp_1.h"
#include "mnist_nn_predict_fmul_32ns_32ns_32_3_max_dsp_1.h"
#include "mnist_nn_predict_fdiv_32ns_32ns_32_12_1.h"
#include "mnist_nn_predict_fexp_32ns_32ns_32_8_full_dsp_1.h"
#include "mnist_nn_predict_weight1.h"
#include "mnist_nn_predict_bias1.h"
#include "mnist_nn_predict_weight2.h"
#include "mnist_nn_predict_bias2.h"
#include "mnist_nn_predict_weight3.h"
#include "mnist_nn_predict_bias3.h"
#include "mnist_nn_predict_output1.h"
#include "mnist_nn_predict_output2.h"
#include "mnist_nn_predict_output3.h"
#include "mnist_nn_predict_CRTL_BUS_s_axi.h"

namespace ap_rtl {

template<unsigned int C_S_AXI_CRTL_BUS_ADDR_WIDTH = 4,
         unsigned int C_S_AXI_CRTL_BUS_DATA_WIDTH = 32>
struct mnist_nn_predict : public sc_module {
    // Port declarations 34
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst_n;
    sc_out< sc_lv<32> > input_r_Addr_A;
    sc_out< sc_logic > input_r_EN_A;
    sc_out< sc_lv<4> > input_r_WEN_A;
    sc_out< sc_lv<32> > input_r_Din_A;
    sc_in< sc_lv<32> > input_r_Dout_A;
    sc_out< sc_logic > input_r_Clk_A;
    sc_out< sc_logic > input_r_Rst_A;
    sc_out< sc_lv<32> > output_r_Addr_A;
    sc_out< sc_logic > output_r_EN_A;
    sc_out< sc_lv<4> > output_r_WEN_A;
    sc_out< sc_lv<32> > output_r_Din_A;
    sc_in< sc_lv<32> > output_r_Dout_A;
    sc_out< sc_logic > output_r_Clk_A;
    sc_out< sc_logic > output_r_Rst_A;
    sc_in< sc_logic > s_axi_CRTL_BUS_AWVALID;
    sc_out< sc_logic > s_axi_CRTL_BUS_AWREADY;
    sc_in< sc_uint<C_S_AXI_CRTL_BUS_ADDR_WIDTH> > s_axi_CRTL_BUS_AWADDR;
    sc_in< sc_logic > s_axi_CRTL_BUS_WVALID;
    sc_out< sc_logic > s_axi_CRTL_BUS_WREADY;
    sc_in< sc_uint<C_S_AXI_CRTL_BUS_DATA_WIDTH> > s_axi_CRTL_BUS_WDATA;
    sc_in< sc_uint<C_S_AXI_CRTL_BUS_DATA_WIDTH/8> > s_axi_CRTL_BUS_WSTRB;
    sc_in< sc_logic > s_axi_CRTL_BUS_ARVALID;
    sc_out< sc_logic > s_axi_CRTL_BUS_ARREADY;
    sc_in< sc_uint<C_S_AXI_CRTL_BUS_ADDR_WIDTH> > s_axi_CRTL_BUS_ARADDR;
    sc_out< sc_logic > s_axi_CRTL_BUS_RVALID;
    sc_in< sc_logic > s_axi_CRTL_BUS_RREADY;
    sc_out< sc_uint<C_S_AXI_CRTL_BUS_DATA_WIDTH> > s_axi_CRTL_BUS_RDATA;
    sc_out< sc_lv<2> > s_axi_CRTL_BUS_RRESP;
    sc_out< sc_logic > s_axi_CRTL_BUS_BVALID;
    sc_in< sc_logic > s_axi_CRTL_BUS_BREADY;
    sc_out< sc_lv<2> > s_axi_CRTL_BUS_BRESP;
    sc_out< sc_logic > interrupt;
    sc_signal< sc_logic > ap_var_for_const0;
    sc_signal< sc_lv<32> > ap_var_for_const2;
    sc_signal< sc_lv<32> > ap_var_for_const1;


    // Module declarations
    mnist_nn_predict(sc_module_name name);
    SC_HAS_PROCESS(mnist_nn_predict);

    ~mnist_nn_predict();

    sc_trace_file* mVcdFile;

    ofstream mHdltvinHandle;
    ofstream mHdltvoutHandle;
    mnist_nn_predict_weight1* weight1_U;
    mnist_nn_predict_bias1* bias1_U;
    mnist_nn_predict_weight2* weight2_U;
    mnist_nn_predict_bias2* bias2_U;
    mnist_nn_predict_weight3* weight3_U;
    mnist_nn_predict_bias3* bias3_U;
    mnist_nn_predict_CRTL_BUS_s_axi<C_S_AXI_CRTL_BUS_ADDR_WIDTH,C_S_AXI_CRTL_BUS_DATA_WIDTH>* mnist_nn_predict_CRTL_BUS_s_axi_U;
    mnist_nn_predict_output1* output1_U;
    mnist_nn_predict_output2* output2_U;
    mnist_nn_predict_output3* output3_U;
    mnist_nn_predict_fadd_32ns_32ns_32_4_full_dsp_1<1,4,32,32,32>* mnist_nn_predict_fadd_32ns_32ns_32_4_full_dsp_1_U1;
    mnist_nn_predict_fmul_32ns_32ns_32_3_max_dsp_1<1,3,32,32,32>* mnist_nn_predict_fmul_32ns_32ns_32_3_max_dsp_1_U2;
    mnist_nn_predict_fdiv_32ns_32ns_32_12_1<1,12,32,32,32>* mnist_nn_predict_fdiv_32ns_32ns_32_12_1_U3;
    mnist_nn_predict_fexp_32ns_32ns_32_8_full_dsp_1<1,8,32,32,32>* mnist_nn_predict_fexp_32ns_32ns_32_8_full_dsp_1_U4;
    sc_signal< sc_logic > ap_rst_n_inv;
    sc_signal< sc_logic > ap_start;
    sc_signal< sc_logic > ap_done;
    sc_signal< sc_logic > ap_idle;
    sc_signal< sc_lv<132> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_logic > ap_ready;
    sc_signal< sc_lv<16> > weight1_address0;
    sc_signal< sc_logic > weight1_ce0;
    sc_signal< sc_lv<32> > weight1_q0;
    sc_signal< sc_lv<6> > bias1_address0;
    sc_signal< sc_logic > bias1_ce0;
    sc_signal< sc_lv<32> > bias1_q0;
    sc_signal< sc_lv<11> > weight2_address0;
    sc_signal< sc_logic > weight2_ce0;
    sc_signal< sc_lv<32> > weight2_q0;
    sc_signal< sc_lv<5> > bias2_address0;
    sc_signal< sc_logic > bias2_ce0;
    sc_signal< sc_lv<32> > bias2_q0;
    sc_signal< sc_lv<9> > weight3_address0;
    sc_signal< sc_logic > weight3_ce0;
    sc_signal< sc_lv<32> > weight3_q0;
    sc_signal< sc_lv<4> > bias3_address0;
    sc_signal< sc_logic > bias3_ce0;
    sc_signal< sc_lv<32> > bias3_q0;
    sc_signal< sc_lv<32> > grp_fu_451_p2;
    sc_signal< sc_lv<32> > reg_465;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_logic > ap_CS_fsm_state50;
    sc_signal< sc_logic > ap_CS_fsm_state93;
    sc_signal< sc_lv<32> > grp_fu_443_p2;
    sc_signal< sc_lv<32> > reg_470;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_logic > ap_CS_fsm_state31;
    sc_signal< sc_logic > ap_CS_fsm_state54;
    sc_signal< sc_logic > ap_CS_fsm_state74;
    sc_signal< sc_logic > ap_CS_fsm_state97;
    sc_signal< sc_logic > ap_CS_fsm_state117;
    sc_signal< sc_lv<32> > reg_478;
    sc_signal< sc_logic > ap_CS_fsm_state16;
    sc_signal< sc_logic > ap_CS_fsm_state59;
    sc_signal< sc_logic > ap_CS_fsm_state102;
    sc_signal< sc_lv<32> > output1_q0;
    sc_signal< sc_lv<32> > reg_485;
    sc_signal< sc_logic > ap_CS_fsm_state19;
    sc_signal< sc_logic > ap_CS_fsm_state47;
    sc_signal< sc_lv<32> > grp_fu_460_p2;
    sc_signal< sc_lv<32> > reg_490;
    sc_signal< sc_logic > ap_CS_fsm_state27;
    sc_signal< sc_logic > ap_CS_fsm_state70;
    sc_signal< sc_logic > ap_CS_fsm_state113;
    sc_signal< sc_lv<32> > grp_fu_455_p2;
    sc_signal< sc_lv<32> > reg_495;
    sc_signal< sc_logic > ap_CS_fsm_state43;
    sc_signal< sc_logic > ap_CS_fsm_state86;
    sc_signal< sc_logic > ap_CS_fsm_state129;
    sc_signal< sc_lv<32> > output2_q0;
    sc_signal< sc_lv<32> > reg_502;
    sc_signal< sc_logic > ap_CS_fsm_state62;
    sc_signal< sc_logic > ap_CS_fsm_state90;
    sc_signal< sc_lv<16> > next_mul_fu_507_p2;
    sc_signal< sc_lv<16> > next_mul_reg_791;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<7> > k_4_fu_519_p2;
    sc_signal< sc_lv<7> > k_4_reg_799;
    sc_signal< sc_lv<64> > tmp_fu_525_p1;
    sc_signal< sc_lv<64> > tmp_reg_804;
    sc_signal< sc_lv<1> > exitcond7_fu_513_p2;
    sc_signal< sc_lv<10> > j_3_fu_535_p2;
    sc_signal< sc_lv<10> > j_3_reg_813;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<1> > exitcond6_fu_529_p2;
    sc_signal< sc_lv<32> > weight1_load_reg_833;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<32> > input_load_reg_838;
    sc_signal< sc_lv<32> > bias1_load_reg_843;
    sc_signal< sc_logic > ap_CS_fsm_state12;
    sc_signal< sc_lv<7> > i_fu_567_p2;
    sc_signal< sc_lv<7> > i_reg_851;
    sc_signal< sc_logic > ap_CS_fsm_state18;
    sc_signal< sc_lv<6> > output1_addr_2_reg_856;
    sc_signal< sc_lv<1> > exitcond_fu_561_p2;
    sc_signal< sc_lv<32> > tmp_12_i_fu_588_p1;
    sc_signal< sc_logic > ap_CS_fsm_state20;
    sc_signal< sc_lv<6> > k_5_fu_599_p2;
    sc_signal< sc_lv<6> > k_5_reg_869;
    sc_signal< sc_logic > ap_CS_fsm_state45;
    sc_signal< sc_lv<64> > tmp_1_fu_605_p1;
    sc_signal< sc_lv<64> > tmp_1_reg_874;
    sc_signal< sc_lv<1> > exitcond5_fu_593_p2;
    sc_signal< sc_lv<13> > tmp_12_cast_fu_617_p1;
    sc_signal< sc_lv<13> > tmp_12_cast_reg_880;
    sc_signal< sc_lv<7> > j_4_fu_627_p2;
    sc_signal< sc_lv<7> > j_4_reg_888;
    sc_signal< sc_logic > ap_CS_fsm_state46;
    sc_signal< sc_lv<1> > exitcond4_fu_621_p2;
    sc_signal< sc_lv<32> > weight2_load_reg_908;
    sc_signal< sc_lv<32> > bias2_load_reg_913;
    sc_signal< sc_logic > ap_CS_fsm_state55;
    sc_signal< sc_lv<6> > i_1_fu_658_p2;
    sc_signal< sc_lv<6> > i_1_reg_921;
    sc_signal< sc_logic > ap_CS_fsm_state61;
    sc_signal< sc_lv<5> > output2_addr_2_reg_926;
    sc_signal< sc_lv<1> > exitcond8_fu_652_p2;
    sc_signal< sc_lv<32> > tmp_12_i1_fu_679_p1;
    sc_signal< sc_logic > ap_CS_fsm_state63;
    sc_signal< sc_lv<4> > k_7_fu_690_p2;
    sc_signal< sc_lv<4> > k_7_reg_939;
    sc_signal< sc_logic > ap_CS_fsm_state88;
    sc_signal< sc_lv<64> > tmp_8_fu_696_p1;
    sc_signal< sc_lv<64> > tmp_8_reg_944;
    sc_signal< sc_lv<1> > exitcond3_fu_684_p2;
    sc_signal< sc_lv<10> > tmp_15_cast_fu_708_p1;
    sc_signal< sc_lv<10> > tmp_15_cast_reg_950;
    sc_signal< sc_lv<6> > j_5_fu_718_p2;
    sc_signal< sc_lv<6> > j_5_reg_958;
    sc_signal< sc_logic > ap_CS_fsm_state89;
    sc_signal< sc_lv<1> > exitcond2_fu_712_p2;
    sc_signal< sc_lv<32> > weight3_load_reg_978;
    sc_signal< sc_lv<32> > bias3_load_reg_983;
    sc_signal< sc_logic > ap_CS_fsm_state98;
    sc_signal< sc_lv<4> > i_2_fu_749_p2;
    sc_signal< sc_lv<4> > i_2_reg_991;
    sc_signal< sc_logic > ap_CS_fsm_state104;
    sc_signal< sc_lv<4> > output3_addr_2_reg_996;
    sc_signal< sc_lv<1> > exitcond9_fu_743_p2;
    sc_signal< sc_lv<32> > output3_q0;
    sc_signal< sc_lv<32> > output3_load_1_reg_1001;
    sc_signal< sc_logic > ap_CS_fsm_state105;
    sc_signal< sc_lv<32> > tmp_12_i2_fu_769_p1;
    sc_signal< sc_logic > ap_CS_fsm_state106;
    sc_signal< sc_lv<4> > k_6_fu_780_p2;
    sc_signal< sc_lv<4> > k_6_reg_1014;
    sc_signal< sc_logic > ap_CS_fsm_state131;
    sc_signal< sc_lv<64> > tmp_3_fu_786_p1;
    sc_signal< sc_lv<64> > tmp_3_reg_1019;
    sc_signal< sc_lv<1> > exitcond1_fu_774_p2;
    sc_signal< sc_lv<6> > output1_address0;
    sc_signal< sc_logic > output1_ce0;
    sc_signal< sc_logic > output1_we0;
    sc_signal< sc_lv<32> > output1_d0;
    sc_signal< sc_lv<5> > output2_address0;
    sc_signal< sc_logic > output2_ce0;
    sc_signal< sc_logic > output2_we0;
    sc_signal< sc_lv<32> > output2_d0;
    sc_signal< sc_lv<4> > output3_address0;
    sc_signal< sc_logic > output3_ce0;
    sc_signal< sc_logic > output3_we0;
    sc_signal< sc_lv<32> > output3_d0;
    sc_signal< sc_lv<7> > k_reg_285;
    sc_signal< sc_logic > ap_CS_fsm_state17;
    sc_signal< sc_lv<16> > phi_mul_reg_296;
    sc_signal< sc_lv<32> > z1_reg_308;
    sc_signal< sc_lv<10> > j_reg_320;
    sc_signal< sc_lv<7> > i_i_reg_331;
    sc_signal< sc_logic > ap_CS_fsm_state44;
    sc_signal< sc_lv<6> > k_1_reg_342;
    sc_signal< sc_logic > ap_CS_fsm_state60;
    sc_signal< sc_lv<7> > j_1_reg_353;
    sc_signal< sc_lv<32> > z2_reg_364;
    sc_signal< sc_lv<6> > i_i9_reg_376;
    sc_signal< sc_logic > ap_CS_fsm_state87;
    sc_signal< sc_lv<4> > k_2_reg_387;
    sc_signal< sc_logic > ap_CS_fsm_state103;
    sc_signal< sc_lv<6> > j_2_reg_398;
    sc_signal< sc_lv<32> > z3_reg_409;
    sc_signal< sc_lv<4> > i_i1_reg_421;
    sc_signal< sc_logic > ap_CS_fsm_state130;
    sc_signal< sc_lv<4> > k_3_reg_432;
    sc_signal< sc_logic > ap_CS_fsm_state132;
    sc_signal< sc_lv<64> > tmp_10_cast_fu_556_p1;
    sc_signal< sc_lv<64> > tmp_4_fu_541_p1;
    sc_signal< sc_lv<64> > tmp_i_fu_573_p1;
    sc_signal< sc_lv<64> > tmp_13_cast_fu_647_p1;
    sc_signal< sc_lv<64> > tmp_s_fu_633_p1;
    sc_signal< sc_lv<64> > tmp_i1_fu_664_p1;
    sc_signal< sc_lv<64> > tmp_16_cast_fu_738_p1;
    sc_signal< sc_lv<64> > tmp_6_fu_724_p1;
    sc_signal< sc_lv<64> > tmp_i2_fu_755_p1;
    sc_signal< sc_lv<32> > input_r_Addr_A_orig;
    sc_signal< sc_lv<32> > output_r_Addr_A_orig;
    sc_signal< sc_lv<32> > grp_fu_443_p0;
    sc_signal< sc_lv<32> > grp_fu_443_p1;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_logic > ap_CS_fsm_state13;
    sc_signal< sc_logic > ap_CS_fsm_state28;
    sc_signal< sc_logic > ap_CS_fsm_state51;
    sc_signal< sc_logic > ap_CS_fsm_state56;
    sc_signal< sc_logic > ap_CS_fsm_state71;
    sc_signal< sc_logic > ap_CS_fsm_state94;
    sc_signal< sc_logic > ap_CS_fsm_state99;
    sc_signal< sc_logic > ap_CS_fsm_state114;
    sc_signal< sc_lv<32> > grp_fu_451_p0;
    sc_signal< sc_lv<32> > grp_fu_451_p1;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_logic > ap_CS_fsm_state48;
    sc_signal< sc_logic > ap_CS_fsm_state91;
    sc_signal< sc_logic > ap_CS_fsm_state32;
    sc_signal< sc_logic > ap_CS_fsm_state75;
    sc_signal< sc_logic > ap_CS_fsm_state118;
    sc_signal< sc_lv<32> > grp_fu_460_p1;
    sc_signal< sc_lv<16> > tmp_4_cast_fu_546_p1;
    sc_signal< sc_lv<16> > tmp_9_fu_550_p2;
    sc_signal< sc_lv<32> > tmp_12_to_int_i_fu_578_p1;
    sc_signal< sc_lv<32> > tmp_12_neg_i_fu_582_p2;
    sc_signal< sc_lv<12> > tmp_10_fu_609_p3;
    sc_signal< sc_lv<13> > tmp_cast_fu_638_p1;
    sc_signal< sc_lv<13> > tmp_11_fu_642_p2;
    sc_signal< sc_lv<32> > tmp_12_to_int_i1_fu_669_p1;
    sc_signal< sc_lv<32> > tmp_12_neg_i1_fu_673_p2;
    sc_signal< sc_lv<9> > tmp_12_fu_700_p3;
    sc_signal< sc_lv<10> > tmp_6_cast_fu_729_p1;
    sc_signal< sc_lv<10> > tmp_13_fu_733_p2;
    sc_signal< sc_lv<32> > tmp_12_to_int_i2_fu_760_p1;
    sc_signal< sc_lv<32> > tmp_12_neg_i2_fu_763_p2;
    sc_signal< sc_lv<132> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<132> ap_ST_fsm_state1;
    static const sc_lv<132> ap_ST_fsm_state2;
    static const sc_lv<132> ap_ST_fsm_state3;
    static const sc_lv<132> ap_ST_fsm_state4;
    static const sc_lv<132> ap_ST_fsm_state5;
    static const sc_lv<132> ap_ST_fsm_state6;
    static const sc_lv<132> ap_ST_fsm_state7;
    static const sc_lv<132> ap_ST_fsm_state8;
    static const sc_lv<132> ap_ST_fsm_state9;
    static const sc_lv<132> ap_ST_fsm_state10;
    static const sc_lv<132> ap_ST_fsm_state11;
    static const sc_lv<132> ap_ST_fsm_state12;
    static const sc_lv<132> ap_ST_fsm_state13;
    static const sc_lv<132> ap_ST_fsm_state14;
    static const sc_lv<132> ap_ST_fsm_state15;
    static const sc_lv<132> ap_ST_fsm_state16;
    static const sc_lv<132> ap_ST_fsm_state17;
    static const sc_lv<132> ap_ST_fsm_state18;
    static const sc_lv<132> ap_ST_fsm_state19;
    static const sc_lv<132> ap_ST_fsm_state20;
    static const sc_lv<132> ap_ST_fsm_state21;
    static const sc_lv<132> ap_ST_fsm_state22;
    static const sc_lv<132> ap_ST_fsm_state23;
    static const sc_lv<132> ap_ST_fsm_state24;
    static const sc_lv<132> ap_ST_fsm_state25;
    static const sc_lv<132> ap_ST_fsm_state26;
    static const sc_lv<132> ap_ST_fsm_state27;
    static const sc_lv<132> ap_ST_fsm_state28;
    static const sc_lv<132> ap_ST_fsm_state29;
    static const sc_lv<132> ap_ST_fsm_state30;
    static const sc_lv<132> ap_ST_fsm_state31;
    static const sc_lv<132> ap_ST_fsm_state32;
    static const sc_lv<132> ap_ST_fsm_state33;
    static const sc_lv<132> ap_ST_fsm_state34;
    static const sc_lv<132> ap_ST_fsm_state35;
    static const sc_lv<132> ap_ST_fsm_state36;
    static const sc_lv<132> ap_ST_fsm_state37;
    static const sc_lv<132> ap_ST_fsm_state38;
    static const sc_lv<132> ap_ST_fsm_state39;
    static const sc_lv<132> ap_ST_fsm_state40;
    static const sc_lv<132> ap_ST_fsm_state41;
    static const sc_lv<132> ap_ST_fsm_state42;
    static const sc_lv<132> ap_ST_fsm_state43;
    static const sc_lv<132> ap_ST_fsm_state44;
    static const sc_lv<132> ap_ST_fsm_state45;
    static const sc_lv<132> ap_ST_fsm_state46;
    static const sc_lv<132> ap_ST_fsm_state47;
    static const sc_lv<132> ap_ST_fsm_state48;
    static const sc_lv<132> ap_ST_fsm_state49;
    static const sc_lv<132> ap_ST_fsm_state50;
    static const sc_lv<132> ap_ST_fsm_state51;
    static const sc_lv<132> ap_ST_fsm_state52;
    static const sc_lv<132> ap_ST_fsm_state53;
    static const sc_lv<132> ap_ST_fsm_state54;
    static const sc_lv<132> ap_ST_fsm_state55;
    static const sc_lv<132> ap_ST_fsm_state56;
    static const sc_lv<132> ap_ST_fsm_state57;
    static const sc_lv<132> ap_ST_fsm_state58;
    static const sc_lv<132> ap_ST_fsm_state59;
    static const sc_lv<132> ap_ST_fsm_state60;
    static const sc_lv<132> ap_ST_fsm_state61;
    static const sc_lv<132> ap_ST_fsm_state62;
    static const sc_lv<132> ap_ST_fsm_state63;
    static const sc_lv<132> ap_ST_fsm_state64;
    static const sc_lv<132> ap_ST_fsm_state65;
    static const sc_lv<132> ap_ST_fsm_state66;
    static const sc_lv<132> ap_ST_fsm_state67;
    static const sc_lv<132> ap_ST_fsm_state68;
    static const sc_lv<132> ap_ST_fsm_state69;
    static const sc_lv<132> ap_ST_fsm_state70;
    static const sc_lv<132> ap_ST_fsm_state71;
    static const sc_lv<132> ap_ST_fsm_state72;
    static const sc_lv<132> ap_ST_fsm_state73;
    static const sc_lv<132> ap_ST_fsm_state74;
    static const sc_lv<132> ap_ST_fsm_state75;
    static const sc_lv<132> ap_ST_fsm_state76;
    static const sc_lv<132> ap_ST_fsm_state77;
    static const sc_lv<132> ap_ST_fsm_state78;
    static const sc_lv<132> ap_ST_fsm_state79;
    static const sc_lv<132> ap_ST_fsm_state80;
    static const sc_lv<132> ap_ST_fsm_state81;
    static const sc_lv<132> ap_ST_fsm_state82;
    static const sc_lv<132> ap_ST_fsm_state83;
    static const sc_lv<132> ap_ST_fsm_state84;
    static const sc_lv<132> ap_ST_fsm_state85;
    static const sc_lv<132> ap_ST_fsm_state86;
    static const sc_lv<132> ap_ST_fsm_state87;
    static const sc_lv<132> ap_ST_fsm_state88;
    static const sc_lv<132> ap_ST_fsm_state89;
    static const sc_lv<132> ap_ST_fsm_state90;
    static const sc_lv<132> ap_ST_fsm_state91;
    static const sc_lv<132> ap_ST_fsm_state92;
    static const sc_lv<132> ap_ST_fsm_state93;
    static const sc_lv<132> ap_ST_fsm_state94;
    static const sc_lv<132> ap_ST_fsm_state95;
    static const sc_lv<132> ap_ST_fsm_state96;
    static const sc_lv<132> ap_ST_fsm_state97;
    static const sc_lv<132> ap_ST_fsm_state98;
    static const sc_lv<132> ap_ST_fsm_state99;
    static const sc_lv<132> ap_ST_fsm_state100;
    static const sc_lv<132> ap_ST_fsm_state101;
    static const sc_lv<132> ap_ST_fsm_state102;
    static const sc_lv<132> ap_ST_fsm_state103;
    static const sc_lv<132> ap_ST_fsm_state104;
    static const sc_lv<132> ap_ST_fsm_state105;
    static const sc_lv<132> ap_ST_fsm_state106;
    static const sc_lv<132> ap_ST_fsm_state107;
    static const sc_lv<132> ap_ST_fsm_state108;
    static const sc_lv<132> ap_ST_fsm_state109;
    static const sc_lv<132> ap_ST_fsm_state110;
    static const sc_lv<132> ap_ST_fsm_state111;
    static const sc_lv<132> ap_ST_fsm_state112;
    static const sc_lv<132> ap_ST_fsm_state113;
    static const sc_lv<132> ap_ST_fsm_state114;
    static const sc_lv<132> ap_ST_fsm_state115;
    static const sc_lv<132> ap_ST_fsm_state116;
    static const sc_lv<132> ap_ST_fsm_state117;
    static const sc_lv<132> ap_ST_fsm_state118;
    static const sc_lv<132> ap_ST_fsm_state119;
    static const sc_lv<132> ap_ST_fsm_state120;
    static const sc_lv<132> ap_ST_fsm_state121;
    static const sc_lv<132> ap_ST_fsm_state122;
    static const sc_lv<132> ap_ST_fsm_state123;
    static const sc_lv<132> ap_ST_fsm_state124;
    static const sc_lv<132> ap_ST_fsm_state125;
    static const sc_lv<132> ap_ST_fsm_state126;
    static const sc_lv<132> ap_ST_fsm_state127;
    static const sc_lv<132> ap_ST_fsm_state128;
    static const sc_lv<132> ap_ST_fsm_state129;
    static const sc_lv<132> ap_ST_fsm_state130;
    static const sc_lv<132> ap_ST_fsm_state131;
    static const sc_lv<132> ap_ST_fsm_state132;
    static const sc_lv<32> ap_const_lv32_0;
    static const int C_S_AXI_DATA_WIDTH;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_31;
    static const sc_lv<32> ap_const_lv32_5C;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_1E;
    static const sc_lv<32> ap_const_lv32_35;
    static const sc_lv<32> ap_const_lv32_49;
    static const sc_lv<32> ap_const_lv32_60;
    static const sc_lv<32> ap_const_lv32_74;
    static const sc_lv<32> ap_const_lv32_F;
    static const sc_lv<32> ap_const_lv32_3A;
    static const sc_lv<32> ap_const_lv32_65;
    static const sc_lv<32> ap_const_lv32_12;
    static const sc_lv<32> ap_const_lv32_2E;
    static const sc_lv<32> ap_const_lv32_1A;
    static const sc_lv<32> ap_const_lv32_45;
    static const sc_lv<32> ap_const_lv32_70;
    static const sc_lv<32> ap_const_lv32_2A;
    static const sc_lv<32> ap_const_lv32_55;
    static const sc_lv<32> ap_const_lv32_80;
    static const sc_lv<32> ap_const_lv32_3D;
    static const sc_lv<32> ap_const_lv32_59;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<32> ap_const_lv32_11;
    static const sc_lv<32> ap_const_lv32_13;
    static const sc_lv<32> ap_const_lv32_2C;
    static const sc_lv<32> ap_const_lv32_2D;
    static const sc_lv<32> ap_const_lv32_36;
    static const sc_lv<32> ap_const_lv32_3C;
    static const sc_lv<32> ap_const_lv32_3E;
    static const sc_lv<32> ap_const_lv32_57;
    static const sc_lv<32> ap_const_lv32_58;
    static const sc_lv<32> ap_const_lv32_61;
    static const sc_lv<32> ap_const_lv32_67;
    static const sc_lv<32> ap_const_lv32_68;
    static const sc_lv<32> ap_const_lv32_69;
    static const sc_lv<32> ap_const_lv32_82;
    static const sc_lv<7> ap_const_lv7_0;
    static const sc_lv<32> ap_const_lv32_10;
    static const sc_lv<16> ap_const_lv16_0;
    static const sc_lv<10> ap_const_lv10_0;
    static const sc_lv<32> ap_const_lv32_2B;
    static const sc_lv<32> ap_const_lv32_3B;
    static const sc_lv<6> ap_const_lv6_0;
    static const sc_lv<32> ap_const_lv32_56;
    static const sc_lv<32> ap_const_lv32_66;
    static const sc_lv<4> ap_const_lv4_0;
    static const sc_lv<32> ap_const_lv32_81;
    static const sc_lv<32> ap_const_lv32_83;
    static const sc_lv<4> ap_const_lv4_F;
    static const sc_lv<32> ap_const_lv32_3F800000;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_1B;
    static const sc_lv<32> ap_const_lv32_32;
    static const sc_lv<32> ap_const_lv32_37;
    static const sc_lv<32> ap_const_lv32_46;
    static const sc_lv<32> ap_const_lv32_5D;
    static const sc_lv<32> ap_const_lv32_62;
    static const sc_lv<32> ap_const_lv32_71;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<32> ap_const_lv32_2F;
    static const sc_lv<32> ap_const_lv32_5A;
    static const sc_lv<32> ap_const_lv32_1F;
    static const sc_lv<32> ap_const_lv32_4A;
    static const sc_lv<32> ap_const_lv32_75;
    static const sc_lv<16> ap_const_lv16_310;
    static const sc_lv<7> ap_const_lv7_40;
    static const sc_lv<7> ap_const_lv7_1;
    static const sc_lv<10> ap_const_lv10_310;
    static const sc_lv<10> ap_const_lv10_1;
    static const sc_lv<32> ap_const_lv32_80000000;
    static const sc_lv<6> ap_const_lv6_20;
    static const sc_lv<6> ap_const_lv6_1;
    static const sc_lv<4> ap_const_lv4_A;
    static const sc_lv<4> ap_const_lv4_1;
    static const sc_lv<5> ap_const_lv5_0;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_var_for_const0();
    void thread_ap_var_for_const2();
    void thread_ap_var_for_const1();
    void thread_ap_clk_no_reset_();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state102();
    void thread_ap_CS_fsm_state103();
    void thread_ap_CS_fsm_state104();
    void thread_ap_CS_fsm_state105();
    void thread_ap_CS_fsm_state106();
    void thread_ap_CS_fsm_state11();
    void thread_ap_CS_fsm_state113();
    void thread_ap_CS_fsm_state114();
    void thread_ap_CS_fsm_state117();
    void thread_ap_CS_fsm_state118();
    void thread_ap_CS_fsm_state12();
    void thread_ap_CS_fsm_state129();
    void thread_ap_CS_fsm_state13();
    void thread_ap_CS_fsm_state130();
    void thread_ap_CS_fsm_state131();
    void thread_ap_CS_fsm_state132();
    void thread_ap_CS_fsm_state16();
    void thread_ap_CS_fsm_state17();
    void thread_ap_CS_fsm_state18();
    void thread_ap_CS_fsm_state19();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state20();
    void thread_ap_CS_fsm_state27();
    void thread_ap_CS_fsm_state28();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state31();
    void thread_ap_CS_fsm_state32();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state43();
    void thread_ap_CS_fsm_state44();
    void thread_ap_CS_fsm_state45();
    void thread_ap_CS_fsm_state46();
    void thread_ap_CS_fsm_state47();
    void thread_ap_CS_fsm_state48();
    void thread_ap_CS_fsm_state5();
    void thread_ap_CS_fsm_state50();
    void thread_ap_CS_fsm_state51();
    void thread_ap_CS_fsm_state54();
    void thread_ap_CS_fsm_state55();
    void thread_ap_CS_fsm_state56();
    void thread_ap_CS_fsm_state59();
    void thread_ap_CS_fsm_state60();
    void thread_ap_CS_fsm_state61();
    void thread_ap_CS_fsm_state62();
    void thread_ap_CS_fsm_state63();
    void thread_ap_CS_fsm_state7();
    void thread_ap_CS_fsm_state70();
    void thread_ap_CS_fsm_state71();
    void thread_ap_CS_fsm_state74();
    void thread_ap_CS_fsm_state75();
    void thread_ap_CS_fsm_state8();
    void thread_ap_CS_fsm_state86();
    void thread_ap_CS_fsm_state87();
    void thread_ap_CS_fsm_state88();
    void thread_ap_CS_fsm_state89();
    void thread_ap_CS_fsm_state90();
    void thread_ap_CS_fsm_state91();
    void thread_ap_CS_fsm_state93();
    void thread_ap_CS_fsm_state94();
    void thread_ap_CS_fsm_state97();
    void thread_ap_CS_fsm_state98();
    void thread_ap_CS_fsm_state99();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_ap_rst_n_inv();
    void thread_bias1_address0();
    void thread_bias1_ce0();
    void thread_bias2_address0();
    void thread_bias2_ce0();
    void thread_bias3_address0();
    void thread_bias3_ce0();
    void thread_exitcond1_fu_774_p2();
    void thread_exitcond2_fu_712_p2();
    void thread_exitcond3_fu_684_p2();
    void thread_exitcond4_fu_621_p2();
    void thread_exitcond5_fu_593_p2();
    void thread_exitcond6_fu_529_p2();
    void thread_exitcond7_fu_513_p2();
    void thread_exitcond8_fu_652_p2();
    void thread_exitcond9_fu_743_p2();
    void thread_exitcond_fu_561_p2();
    void thread_grp_fu_443_p0();
    void thread_grp_fu_443_p1();
    void thread_grp_fu_451_p0();
    void thread_grp_fu_451_p1();
    void thread_grp_fu_460_p1();
    void thread_i_1_fu_658_p2();
    void thread_i_2_fu_749_p2();
    void thread_i_fu_567_p2();
    void thread_input_r_Addr_A();
    void thread_input_r_Addr_A_orig();
    void thread_input_r_Clk_A();
    void thread_input_r_Din_A();
    void thread_input_r_EN_A();
    void thread_input_r_Rst_A();
    void thread_input_r_WEN_A();
    void thread_j_3_fu_535_p2();
    void thread_j_4_fu_627_p2();
    void thread_j_5_fu_718_p2();
    void thread_k_4_fu_519_p2();
    void thread_k_5_fu_599_p2();
    void thread_k_6_fu_780_p2();
    void thread_k_7_fu_690_p2();
    void thread_next_mul_fu_507_p2();
    void thread_output1_address0();
    void thread_output1_ce0();
    void thread_output1_d0();
    void thread_output1_we0();
    void thread_output2_address0();
    void thread_output2_ce0();
    void thread_output2_d0();
    void thread_output2_we0();
    void thread_output3_address0();
    void thread_output3_ce0();
    void thread_output3_d0();
    void thread_output3_we0();
    void thread_output_r_Addr_A();
    void thread_output_r_Addr_A_orig();
    void thread_output_r_Clk_A();
    void thread_output_r_Din_A();
    void thread_output_r_EN_A();
    void thread_output_r_Rst_A();
    void thread_output_r_WEN_A();
    void thread_tmp_10_cast_fu_556_p1();
    void thread_tmp_10_fu_609_p3();
    void thread_tmp_11_fu_642_p2();
    void thread_tmp_12_cast_fu_617_p1();
    void thread_tmp_12_fu_700_p3();
    void thread_tmp_12_i1_fu_679_p1();
    void thread_tmp_12_i2_fu_769_p1();
    void thread_tmp_12_i_fu_588_p1();
    void thread_tmp_12_neg_i1_fu_673_p2();
    void thread_tmp_12_neg_i2_fu_763_p2();
    void thread_tmp_12_neg_i_fu_582_p2();
    void thread_tmp_12_to_int_i1_fu_669_p1();
    void thread_tmp_12_to_int_i2_fu_760_p1();
    void thread_tmp_12_to_int_i_fu_578_p1();
    void thread_tmp_13_cast_fu_647_p1();
    void thread_tmp_13_fu_733_p2();
    void thread_tmp_15_cast_fu_708_p1();
    void thread_tmp_16_cast_fu_738_p1();
    void thread_tmp_1_fu_605_p1();
    void thread_tmp_3_fu_786_p1();
    void thread_tmp_4_cast_fu_546_p1();
    void thread_tmp_4_fu_541_p1();
    void thread_tmp_6_cast_fu_729_p1();
    void thread_tmp_6_fu_724_p1();
    void thread_tmp_8_fu_696_p1();
    void thread_tmp_9_fu_550_p2();
    void thread_tmp_cast_fu_638_p1();
    void thread_tmp_fu_525_p1();
    void thread_tmp_i1_fu_664_p1();
    void thread_tmp_i2_fu_755_p1();
    void thread_tmp_i_fu_573_p1();
    void thread_tmp_s_fu_633_p1();
    void thread_weight1_address0();
    void thread_weight1_ce0();
    void thread_weight2_address0();
    void thread_weight2_ce0();
    void thread_weight3_address0();
    void thread_weight3_ce0();
    void thread_ap_NS_fsm();
    void thread_hdltv_gen();
};

}

using namespace ap_rtl;

#endif