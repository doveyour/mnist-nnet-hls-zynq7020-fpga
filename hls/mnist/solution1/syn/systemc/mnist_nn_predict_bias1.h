// ==============================================================
// File generated on Mon May 10 08:06:06 CST 2021
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mnist_nn_predict_bias1_H__
#define __mnist_nn_predict_bias1_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mnist_nn_predict_bias1_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 32;
  static const unsigned AddressRange = 64;
  static const unsigned AddressWidth = 6;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(mnist_nn_predict_bias1_ram) {
        ram[0] = "0b00111101000001000011010011111110";
        ram[1] = "0b10111110010001100010100111011000";
        ram[2] = "0b10111110010101001111011110010101";
        ram[3] = "0b00111101101010000110100111100001";
        ram[4] = "0b00111101111101001010110011001011";
        ram[5] = "0b00111110000010111010011100100101";
        ram[6] = "0b00111101100000101010010011000000";
        ram[7] = "0b00111101011011010100000001000000";
        ram[8] = "0b10111110101100000011001110010100";
        ram[9] = "0b10111110000001110101101011111011";
        ram[10] = "0b10111110100100010000111010010110";
        ram[11] = "0b00111101101010110011000111010000";
        ram[12] = "0b10111110001011110000010001101100";
        ram[13] = "0b00111101101010100101101001000111";
        ram[14] = "0b10111110011111111001000100010000";
        ram[15] = "0b10111110011000011010111011010101";
        ram[16] = "0b10111101011100000011000000101111";
        ram[17] = "0b00111101000010110100110000010100";
        ram[18] = "0b10111110111100100101001110110110";
        ram[19] = "0b10111110011111100101111111000101";
        ram[20] = "0b10111110000101000011110101000111";
        ram[21] = "0b10111110001001011111100101000101";
        ram[22] = "0b10111101101000010010000111010100";
        ram[23] = "0b00111110011001110011000011001101";
        ram[24] = "0b00111101000011101001100011001111";
        ram[25] = "0b00111101100010100101101001010100";
        ram[26] = "0b00111101101100001100100010001010";
        ram[27] = "0b10111101100110011000101000010101";
        ram[28] = "0b10111110101101011000010110011101";
        ram[29] = "0b00111110001001011110001010011111";
        ram[30] = "0b10111100111100101110101101000101";
        ram[31] = "0b00111111000000100110011000011001";
        ram[32] = "0b00111101101101001100101110111010";
        ram[33] = "0b00111101110010111000111101011000";
        ram[34] = "0b10111110000001110111101011001110";
        ram[35] = "0b00111100110000000100111010100101";
        ram[36] = "0b10111100101101011001100000110011";
        ram[37] = "0b10111110100000011000001110000100";
        ram[38] = "0b00111110011111110100011110100010";
        ram[39] = "0b10111101111011110101000011110001";
        ram[40] = "0b10111110000000000101000001110100";
        ram[41] = "0b00111110011000000001001011011001";
        ram[42] = "0b00111110110101011010101001100111";
        ram[43] = "0b10111101101010111100011111101010";
        ram[44] = "0b10111110100101011100110001111000";
        ram[45] = "0b10111110000000011011000001000111";
        ram[46] = "0b00111110000001000100111010001101";
        ram[47] = "0b00111110011101010100100110000111";
        ram[48] = "0b00111110100111111100001010010100";
        ram[49] = "0b10111100101100001001000010001100";
        ram[50] = "0b00111110001100110000100111011100";
        ram[51] = "0b00111101010011100101011101100001";
        ram[52] = "0b00111110100100001101110010001011";
        ram[53] = "0b00111101011100011111000101111111";
        ram[54] = "0b10111101100110100011000101111100";
        ram[55] = "0b00111101111000000110000111001000";
        ram[56] = "0b00111101101100110001000000100000";
        ram[57] = "0b00111101110100001101011010100101";
        ram[58] = "0b00111101001011110001011000111000";
        ram[59] = "0b10111101011110001010011111001100";
        ram[60] = "0b10111010110111001011110100000101";
        ram[61] = "0b00111101000110001100000001010110";
        ram[62] = "0b10111110101010111111110100011010";
        ram[63] = "0b00111110001000010001011101111111";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(mnist_nn_predict_bias1) {


static const unsigned DataWidth = 32;
static const unsigned AddressRange = 64;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mnist_nn_predict_bias1_ram* meminst;


SC_CTOR(mnist_nn_predict_bias1) {
meminst = new mnist_nn_predict_bias1_ram("mnist_nn_predict_bias1_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mnist_nn_predict_bias1() {
    delete meminst;
}


};//endmodule
#endif
