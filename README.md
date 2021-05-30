# mnist-nnet-hls-zynq7020-fpga

to illustrate how to  removal a Neural Network from pc to FPGA board ,it contain all the code include c code worked in pc,HLS prj accelerate code in FPGA,and implacement in block  design and with SDK app......

## **cnet**

the Neural Network c code ,you can train the nnet and test in this proj by pc

cd cnet/mnist

**make** -----to generate the libnet.a  Library file  

**make  train** --- to generate  the elf file in linux system and train the nnet in PC and 

 deploy with  ./train   ,you can  get the weight file in   ./mnist/out  until the train over ,,it contain  both pc file  and FPGA  file which can be used by hls  format with ".dat",you can recognise them by differernt name 

**make  test-**-- to generate the elf file in linux syetem   and test the nnet's  accuracy and show

and  deploy with  ./train in linux 

**make  save_data** ---to generate the  data file from  orign file to  format ".dat"

deployed  ways   ./save_data,you can modefythe number in source file to change the number of files  which  can be used in HLS proj  or  used  in SDK  proj   ,,they  named "id_true.dat".

## hls

the  project code to  generate  the HLS  ip  core   which  can be used  in FPGA

## **vivado**

the  project code contain the block design  and  the .bit file   and   .hdf   ,



you can reference   to csdn   link:https://blog.csdn.net/u012116328/article/details/117246023

-------

from SDU  CNSATM TEAM!
