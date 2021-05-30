//****************************************Copyright (c)***********************************//

// Created date:        2019/10/8 17:25:36
// Version:             V1.0
// Descriptions:        The original version
//
//----------------------------------------------------------------------------------------
//****************************************************************************************//

#include "xparameters.h"
#include "xil_printf.h"
#include "ff.h"
#include "xdevcfg.h"
#include  <stdio.h>
#include  <stdlib.h>
#include "platform.h"
#include "xil_printf.h"
#include "xil_io.h"
#include "xmnist_nn_predict.h"

#define FILE_NAME "1.dat"                //定义文件名

const char src_str[30] = "www.openedv.com"; //定义文本内容
static FATFS fatfs;     //文件系统

u32 float_to_u32(float value)
{
	u32 result;
	union float_byte
	{
		float v;
		u8 byte[4];
	}data;
	data.v =value ;
	result = (data.byte[3]<<24)+(data.byte[2]<<16)+(data.byte[1]<<8)+(data.byte[0]<<0);
	return result;
}
float u32_to_float(u32 value)
{
	return *((float*)&value);
}
//初始化文件系统
int platform_init_fs()
{
	FRESULT status;
	TCHAR *Path = "0:/";
	BYTE work[FF_MAX_SS];

    //注册一个工作区(挂载分区文件系统)
    //在使用任何其它文件函数之前，必须使用f_mount函数为每个使用卷注册一个工作区
	status = f_mount(&fatfs, Path, 0);  //挂载SD卡
	if (status != FR_OK) {
		xil_printf("Volume is not FAT formated; formating FAT\r\n");

	}
	return 0;
}

//挂载SD(TF)卡
int sd_mount()
{
    FRESULT status;
    //初始化文件系统（挂载SD卡，如果挂载不成功，则格式化SD卡）
    status = platform_init_fs();
    if(status){
        xil_printf("ERROR: f_mount returned %d!\n",status);
        return XST_FAILURE;
    }
    return XST_SUCCESS;
}

//SD卡写数据
int sd_write_data(char *file_name,u32 src_addr,u32 byte_len)
{
    FIL fil;         //文件对象
    UINT bw;         //f_write函数返回已写入的字节数

    //打开一个文件,如果不存在，则创建一个文件
    f_open(&fil,file_name,FA_CREATE_ALWAYS | FA_WRITE);
    //移动打开的文件对象的文件读/写指针     0:指向文件开头
    f_lseek(&fil, 0);
    //向文件中写入数据
    f_write(&fil,(void*) src_addr,byte_len,&bw);
    //关闭文件
    f_close(&fil);
    return 0;
}

//SD卡读数据
int sd_read_data(char *file_name,u32 src_addr,u32 byte_len)
{
	FIL fil;         //文件对象
    UINT br;         //f_read函数返回已读出的字节数

    //打开一个只读的文件
    f_open(&fil,file_name,FA_READ);
    //移动打开的文件对象的文件读/写指针     0:指向文件开头
    f_lseek(&fil,0);
    //从SD卡中读出数据
    f_read(&fil,(void*)src_addr,byte_len,&br);
    //关闭文件
    f_close(&fil);
    return br;
}

//main函数
int main()
{
	FIL fil;         //文件对象
	int flielen,br;
	char dest_str[5000] = "";
	char dest_str0[5000] = "";
	char dest_str1[784][10] = {{0}};
	float f_buff;//teapota float
	char  buff[10] = {0};
	float data[784] = {0};
	char *p;
	u32 result, revs;;
    int status,len,i,k;
    int n = 0;


   // init_platform();
    Xil_DCacheDisable();
    //scleanup_platform();
    printf("sd_mount start\n");
    //挂载SD卡
    status = sd_mount();

    if(status != XST_SUCCESS)
    {
    	printf("sd_mount failed\n");
		return 0;
    }
    //get the file from sd
    f_open(&fil,FILE_NAME,FA_READ);
  //移动打开的文件对象的文件读/写指针    0:指向文件开头
    f_lseek(&fil,0);
// read file
    f_read(&fil,(void*)dest_str,5000,&br);
   //to devide  str to several numeral str
    p = strtok(dest_str,",\n\r");
    memcpy(dest_str1[0],p,strlen(p));
    i =1;
    // 继续获取其他的子字符串
     while( p != NULL )
     {
    	 p = strtok(NULL, ",\n\r");
    	 memcpy(dest_str1[i++],p,strlen(p));
     }
     //tran str to float
    for(i=0;i<784;i++)
    {
    	data[i] = atof(dest_str1[i]);

    	//printf("dest_str1[i]:%f\n",data[i]);
    }
    printf("data show:\n");
    for( k=0;k<28;k++)
	{

		for( i=0;i<28;i++)
		{
			printf("%.0f",data[n++]);
		}
		printf("\n");

	}

    for(i=0;i<784;i++)
    {
		result = float_to_u32(data[i]);
		Xil_Out32(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR+i*4,result);
   	}
//init  the pl  neron net
    XMnist_nn_predict HlsXMem_test;
	XMnist_nn_predict_Config *ExamplePtr;
	printf("Look Up the device configuration.\n");
	ExamplePtr = XMnist_nn_predict_LookupConfig(XPAR_MNIST_NN_PREDICT_0_DEVICE_ID);
	if (!ExamplePtr)
	{
		printf("ERROR: Lookup of accelerator configuration failed.\n\r");
		return XST_FAILURE;
	}
	printf("Initialize the Device\n");
	status = XMnist_nn_predict_CfgInitialize(&HlsXMem_test, ExamplePtr);
	if (status != XST_SUCCESS)
	{
		printf("ERROR: Could not initialize accelerator.\n\r");
		return(-1);
	}

	XMnist_nn_predict_Start(&HlsXMem_test);
	while (XMnist_nn_predict_IsDone(&HlsXMem_test) == 0);
	for(i=0;i<10;i++)
	{
		revs=Xil_In32(XPAR_AXI_BRAM_CTRL_1_S_AXI_BASEADDR+4*i);
		float recvf = u32_to_float(revs);
		printf("recongnize result:%f\n",recvf);
	 }
	printf("all vision over\n");
	cleanup_platform();
	return 0;
  }
