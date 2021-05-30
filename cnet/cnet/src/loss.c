/*****************************************************************************
 *                                  LOSS
 * Implementation of the available loss functions.
 ****************************************************************************/

#include <math.h>
#include <float.h>
#include "loss.h"
#include "helpers.h"


/// Mean Squared Error


/**
 * Mean Squared Error.
 *
 * @param double *: Prediction
 * @param double *: Target
 * @param int : size
 * @return double
 */
double MSE(double const *pred,double const *target,int size)
{
    double mse = 0;
    for(int i = 0; i < size; i++)
        mse += pow(pred[i] - target[i], 2);
    return mse / size;
}


/**
 * Mean Squared Error Derivative
 *
 * @param double *: Prediction
 * @param double *: Target
 * @param double *: Destination array
 * @param int: Size of the given arrays
 */
void MSE_Dx(double const *pred,double const *target,double *dst,int size)
{
    for(int i = 0; i < size; i++)
        dst[i] = 2 * (pred[i] - target[i]);
}


/// Cross Entropy


/**
 * Cross Entropy
 *
 * @param double *: Prediction
 * @param double *: Target
 * @param int : size
 * @return double
 */
double CrossEntropy(
    double const *pred,
    double const *target,
    int size
){
    double ce = 0;

    for(int i = 0; i < size; i++)
        ce -= target[i] * log(non_zero(pred[i]));

    return ce;
}


/**
 * Cross Entropy Derivative
 *
 * @param double *: Prediction
 * @param double *: Target
 * @param double *: Destination array
 * @param int: Size of the given arrays
 */
void CrossEntropy_Dx(
    double const *pred,
    double const *target,
    double *dst,
    int size
){
    for(int i = 0; i < size; i++)
        dst[i] = (pred[i] - target[i]);
}


/// Helpers


cnet_loss_func *cnet_get_loss(enum cnet_loss_type type) {
    switch(type) {
        case mse_loss: return MSE;
        case cross_entropy_loss: return CrossEntropy;
    }
}


cnet_loss_func_dx *cnet_get_loss_dx(enum cnet_loss_type type) {
    switch(type) {
        case mse_loss: return MSE_Dx;
        case cross_entropy_loss: return CrossEntropy_Dx;
    }
}
