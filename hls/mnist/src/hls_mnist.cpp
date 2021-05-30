/**
 * Use the saved CNet model to predict over the MNIST dataset. compile by  hls 
 **/

#include <math.h>
#include "hls_mnist.h"

/**
 * Sigmoid
 *
 * @param double *: Sum of weights * inputs + Bias
 * @param int: Size
 */
void Sigmoid( float *a,int size)
{
    for(int i = 0; i < size; i++)
      a[i] = 1/(1 + expf(-a[i]));
}

//void mnist_nn_predict(float weight1[200704],float weight2[32768],float weight3[1280],float bias1[256],float bias2[128],float bias3[10],float input[784],float output[10])
void mnist_nn_predict( float input[784],float output[10])
{
#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS
#pragma HLS INTERFACE bram port=input
#pragma HLS INTERFACE bram port=output


	int max_idx = 0;

    // initialize the weight matrix
	const float weight1[64][784] = {
			#include "weight1.dat"
			};
    const float weight2[32][64] = {
    		#include "weight2.dat"
    		};
    const float weight3[10][32]  = {
    		#include "weight3.dat"
    		};
    // initialize the bias matrix
	const float bias1[64] = {
			#include "bias1.dat"
			};
	const float bias2[32] = {
			#include "bias2.dat"
			};
	const float bias3[10]  = {
			#include "bias3.dat"
			};


    // initialize the confusion matrix
	int k ,j,i;
	    //float *in = input;
		//float *out = output;
		float output1[64];
		float output2[32];
		float output3[10];
		float z1 = 0.0;
		float z2 = 0.0;
		float z3 = 0.0;
	    // pass through every layer in the net



	        // pass through every neuron in the net

	      //the first layer
	        for( k = 0; k < 64; k++)
			{
	        	z1 = 0.0;
	            // compute z for neuron
	            for( j = 0; j < 784; j++)
	                //z1 += weight1[k*784+j] * input[j];
	            	z1 += weight1[k][j] * input[j];
	            z1 += bias1[k];
	            output1[k] = z1;

	        }
			Sigmoid(output1,64);

			 //the second layer


			 for( k = 0; k < 32; k++)
			 {
	            // compute z for neuron
				 z2= 0.0;
	            for( j = 0; j < 64; j++)
	                //z2 += weight2[k*256+j] * output1[j];
	            	z2 += weight2[k][j] * output1[j];
	            z2 += bias2[k];
	            output2[k] = z2;

	         }
			 Sigmoid(output2,32);

			 //the third layer
			 for( k = 0; k < 10; k++)
			 {
	            // compute z for neuron
				 z3 = 0.0;
	            for( j = 0; j < 32; j++)
	                //z3 += weight3[k*128+j] * output2[j];
	            	z3 += weight3[k][j] * output2[j];
	            z3 += bias3[k];
	            output3[k] = z3;

	         }

	        Sigmoid(output3,10);

	        for( k = 0; k < 10; k++)
			output[k] = output3[k];



	            for( i = 0; i < 10; i++) {
	                if(output[i] > output[max_idx]) {
	                    max_idx = i;
	                }
	            }
	          //  return max_idx;


}
