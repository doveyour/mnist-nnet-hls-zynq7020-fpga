// ==============================================================
// File generated on Mon May 10 08:06:06 CST 2021
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mnist_nn_predict_bias2_H__
#define __mnist_nn_predict_bias2_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mnist_nn_predict_bias2_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 32;
  static const unsigned AddressRange = 32;
  static const unsigned AddressWidth = 5;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(mnist_nn_predict_bias2_ram) {
        ram[0] = "0b00111110001011010100001000000001";
        ram[1] = "0b00111101000110000110101001011010";
        ram[2] = "0b10111110000100011010111100110011";
        ram[3] = "0b10111110001110100000111110010111";
        ram[4] = "0b00111110000110011110100010000001";
        ram[5] = "0b10111101100111111011101010010110";
        ram[6] = "0b10111100001110111111000110110011";
        ram[7] = "0b00111100101111000111001101001110";
        ram[8] = "0b10111110011010100110010110000110";
        ram[9] = "0b00111110011011111111111100010101";
        ram[10] = "0b10111101000000011011101111011101";
        ram[11] = "0b10111100101111001101100101101111";
        ram[12] = "0b10111011100111000100101001001110";
        ram[13] = "0b00111110000100111101010010001101";
        ram[14] = "0b00111100101111111011100001111101";
        ram[15] = "0b00111100110111111001101100111011";
        ram[16] = "0b10111110001000011111010100101011";
        ram[17] = "0b10111101100000000000011101100100";
        ram[18] = "0b00111101100110001111101011001011";
        ram[19] = "0b10111100011100110110000010110101";
        ram[20] = "0b00111110001010010011011000010000";
        ram[21] = "0b10111100010111101010110011001001";
        ram[22] = "0b10111100110011011001100000000100";
        ram[23] = "0b10111101110111101010011011110111";
        ram[24] = "0b10111110011111111010011110101111";
        ram[25] = "0b00111101110010111010111111110100";
        ram[26] = "0b00111101000001000110101110000101";
        ram[27] = "0b00111101101100100101110100000111";
        ram[28] = "0b10111011010101110110001001010010";
        ram[29] = "0b00111110010111001110011001110000";
        ram[30] = "0b00111100101010011111101011011011";
        ram[31] = "0b00111101001110001001010110101000";


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


SC_MODULE(mnist_nn_predict_bias2) {


static const unsigned DataWidth = 32;
static const unsigned AddressRange = 32;
static const unsigned AddressWidth = 5;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mnist_nn_predict_bias2_ram* meminst;


SC_CTOR(mnist_nn_predict_bias2) {
meminst = new mnist_nn_predict_bias2_ram("mnist_nn_predict_bias2_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mnist_nn_predict_bias2() {
    delete meminst;
}


};//endmodule
#endif
