-- ==============================================================
-- File generated on Mon May 10 08:06:06 CST 2021
-- Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
-- SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
-- IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity mnist_nn_predict_bias2_rom is 
    generic(
             DWIDTH     : integer := 32; 
             AWIDTH     : integer := 5; 
             MEM_SIZE    : integer := 32
    ); 
    port (
          addr0      : in std_logic_vector(AWIDTH-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DWIDTH-1 downto 0);
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of mnist_nn_predict_bias2_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "00111110001011010100001000000001", 
    1 => "00111101000110000110101001011010", 
    2 => "10111110000100011010111100110011", 
    3 => "10111110001110100000111110010111", 
    4 => "00111110000110011110100010000001", 
    5 => "10111101100111111011101010010110", 
    6 => "10111100001110111111000110110011", 
    7 => "00111100101111000111001101001110", 
    8 => "10111110011010100110010110000110", 
    9 => "00111110011011111111111100010101", 
    10 => "10111101000000011011101111011101", 
    11 => "10111100101111001101100101101111", 
    12 => "10111011100111000100101001001110", 
    13 => "00111110000100111101010010001101", 
    14 => "00111100101111111011100001111101", 
    15 => "00111100110111111001101100111011", 
    16 => "10111110001000011111010100101011", 
    17 => "10111101100000000000011101100100", 
    18 => "00111101100110001111101011001011", 
    19 => "10111100011100110110000010110101", 
    20 => "00111110001010010011011000010000", 
    21 => "10111100010111101010110011001001", 
    22 => "10111100110011011001100000000100", 
    23 => "10111101110111101010011011110111", 
    24 => "10111110011111111010011110101111", 
    25 => "00111101110010111010111111110100", 
    26 => "00111101000001000110101110000101", 
    27 => "00111101101100100101110100000111", 
    28 => "10111011010101110110001001010010", 
    29 => "00111110010111001110011001110000", 
    30 => "00111100101010011111101011011011", 
    31 => "00111101001110001001010110101000" );


begin 


memory_access_guard_0: process (addr0) 
begin
      addr0_tmp <= addr0;
--synthesis translate_off
      if (CONV_INTEGER(addr0) > mem_size-1) then
           addr0_tmp <= (others => '0');
      else 
           addr0_tmp <= addr0;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem(CONV_INTEGER(addr0_tmp)); 
        end if;
    end if;
end process;

end rtl;

Library IEEE;
use IEEE.std_logic_1164.all;

entity mnist_nn_predict_bias2 is
    generic (
        DataWidth : INTEGER := 32;
        AddressRange : INTEGER := 32;
        AddressWidth : INTEGER := 5);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of mnist_nn_predict_bias2 is
    component mnist_nn_predict_bias2_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mnist_nn_predict_bias2_rom_U :  component mnist_nn_predict_bias2_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


