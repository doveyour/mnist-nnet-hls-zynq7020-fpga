#include <iostream>
#include <fstream>
#include "hls_mnist.h"

void load_data(const char* path, char* ptr, unsigned int size)
{
	std::ifstream f(path, std::ios::in | std::ios::binary);
	if (!f)
	{
		std::cout << path<<" no such file,please check the file name!/n";
		exit(0);
	}

	f.read(ptr, size);
	f.close();
}
int j,k;
int n=0;
int m=0;
int main()
{
// initialize the weight matrix
	/*
 float weight1[256][784] = {
		#include "weight1.dat"
		};
 float weight2[128][256] = {
		#include "weight2.dat"
		};
 float weight3[10][128] = {
		#include "weight3.dat"		};*/
/*
   float weight1[200704] = {
		#include "weight1_.dat"
		};
 float weight2[32768] = {
		#include "weight2_.dat"
		};
 float weight3[1280] = {
		#include "weight3_.dat"
		};
*/


// initialize the bias matrix
 /*float bias1[64] = {
		#include "bias1.dat"
		};
 float bias2[32] = {
		#include "bias2.dat"
		};
 float bias3[10]  = {
		#include "bias3.dat"
		};
*/
	 float  input[784] =
	{
		#include "./0.dat"
	};
	//initialize feature
	float printin[28*28];
	float in[28 * 28];
	float output[10]={0};
	//load_data("/home/dy/Desktop/myhls/mnist/mnist/code/2.dat", (char*)in, sizeof(in));
	//load_data("/home/dy/Desktop/myhls/mnist/mnist/code/2t.dat", (char*)printin, sizeof(printin));
	//initialize weight and bias
	//printf("%d\n",strlen((const char *)in));
	for( k=0;k<28;k++)
	{

		for( j=0;j<28;j++)
		{
			printf("%.0f",input[n++]);
		}
		printf("\n");

	}
     mnist_nn_predict(input,output);
	//mnist_nn_predict(weight1,weight2,weight3,bias1,bias2,bias3,input,output);
	//lenet(input,weight_all,bias_all,out);
	for (int i=0;i<10;i++)
		printf("%.5f ",output[i]);
	printf("%d\n",n);
	return 0;
}
