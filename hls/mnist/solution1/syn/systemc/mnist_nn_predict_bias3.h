// ==============================================================
// File generated on Mon May 10 08:06:06 CST 2021
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mnist_nn_predict_bias3_H__
#define __mnist_nn_predict_bias3_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mnist_nn_predict_bias3_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 32;
  static const unsigned AddressRange = 10;
  static const unsigned AddressWidth = 4;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(mnist_nn_predict_bias3_ram) {
        ram[0] = "0b10111111001100000010100000110000";
        ram[1] = "0b10111110101000000000001010010101";
        ram[2] = "0b10111111001101001111000011011101";
        ram[3] = "0b10111111000010111101001011110010";
        ram[4] = "0b10111111010111001000010110001001";
        ram[5] = "0b10111110010010111001111111001000";
        ram[6] = "0b10111111011011001011101111000110";
        ram[7] = "0b10111111000011010011101010001010";
        ram[8] = "0b10111111001011011100111010101100";
        ram[9] = "0b10111110011111100011100111010110";


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


SC_MODULE(mnist_nn_predict_bias3) {


static const unsigned DataWidth = 32;
static const unsigned AddressRange = 10;
static const unsigned AddressWidth = 4;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mnist_nn_predict_bias3_ram* meminst;


SC_CTOR(mnist_nn_predict_bias3) {
meminst = new mnist_nn_predict_bias3_ram("mnist_nn_predict_bias3_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mnist_nn_predict_bias3() {
    delete meminst;
}


};//endmodule
#endif
