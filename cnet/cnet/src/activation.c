/*****************************************************************************
 *                               ACTIVATION
 * Implementation of available activation functions and some helpers.
 ****************************************************************************/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "activation.h"
#include "helpers.h"
#pragma clang diagnostic ignored "-Wunused-parameter"


/// ReLU


/**
 * ReLU
 * Rectified Linear Units.
 *
 * @param double *: Sum of weights * inputs + Bias
 * @param int: Size
 */
void ReLU(
    double *a,
    int size
){
    for(int i = 0; i < size; i++)
        a[i] = a[i] > 0 ? a[i] : 0;
}


/**
 * ReLU Derivative.
 *
 * @param double: ReLU Output
 * @return double: ReLU Derivative
 */
double ReLU_Dx(
    double s
){
    return s >= 0 ? 1 : 0;
}


/// Sigmoid


/**
 * Sigmoid
 *
 * @param double *: Sum of weights * inputs + Bias
 * @param int: Size
 */
void Sigmoid(
    double *a,
    int size
){
    for(int i = 0; i < size; i++)
        a[i] = 1/(1 + expf(-a[i]));
}


/**
 * Sigmoid Derivative
 *
 *
 * @param double: Sigmoid Output
 * @return double: Sigmoid Derivative
 */
double Sigmoid_Dx(
    double s
){
    return s * (1 - s);
}


/// SoftMax


/**
 * SoftMax
 *
 * @param double *: Sum of weights * inputs + Bias
 * @param int: Size
 */
void SoftMax(
    double *a,
    int size
){
    // get max z
    double max = a[0];
    for(int i = 0; i < size; i++)
        max = max < a[i] ? a[i] : max;

    // sum of exp(z - max)
    double sum = 0;
    for(int i = 0; i < size; i++)
        sum += expf(a[i] - max);

    // populate the destination array
    for(int i = 0; i < size; i++)
        a[i] = expf(a[i] - max) / sum;
}


/**
 * SoftMax Derivative
 *
 * We don't do anything here, just return 1, as the derivative is
 * already handled in the derivative of the cross entropy loss.
 * As per this, we cannot use the cross entropy with anything else than
 * the softmax.
 *
 * @param double *s: The output vector of the softmax function
 * @param double **d: Destination Matrix
 * @param int size: Input Z size (Jacobian Matrix size being: size x size)
 */
double SoftMax_Dx(
   // double s
){
    return 1.0;
}


/// Helpers


cnet_act_func *cnet_get_act(enum cnet_act_type type) {
    switch(type) {
        case relu_act: return ReLU;
        case sigmoid_act: return Sigmoid;
        case softmax_act: return SoftMax;
    }
	return 0;
}


cnet_act_func_dx *cnet_get_act_dx(enum cnet_act_type type) {
    switch(type) {
        case relu_act: return ReLU_Dx;
        case sigmoid_act: return Sigmoid_Dx;
        case softmax_act: return SoftMax_Dx;
    }
	return 0;
}


