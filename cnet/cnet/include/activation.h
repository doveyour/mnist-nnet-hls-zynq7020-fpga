/*****************************************************************************
 *                               ACTIVATION
 * Available activation functions and some helpers.
 ****************************************************************************/

#ifndef CNET_ACTIVATION_H
#define CNET_ACTIVATION_H


enum cnet_act_type {
    relu_act = 0,                   // Rectified Linear Units
    sigmoid_act,                // Sigmoid
    softmax_act                 // Softmax
};


/**
 * Activation Function
 *
 * These functions will be in charge of performing in-place activation
 * for the sum of weights * inputs in a layer.
 *
 * @param double *: Sum of weights * inputs + Bias
 * @param int: Size
 */
typedef void cnet_act_func(double *, int); 


/**
 * Activation Function Derivative.
 *
 * This funcions will be in charge of computing the activation derivative.
 * The resulting value will be used, in conjunction with the cost
 * derivative, to compute the layer's delta.
 * IMPORTANT:
 *  - it will take as parameter the layer's output, and not the
 *    original values fed to the function.
 *  - it takes a single number, as the responsibility to update
 *    the layers delta using this value corresponds to the layer.
 *
 * @param double: Activation Output
 * @return double: Activation Derivative
 */
typedef double cnet_act_func_dx(
    double
);


/**
 * Get activation function by type 
 *
 * Returns a pointer to the activation function implementation,
 * for the given type.
 *
 * @param enum cnet_act_type: Activation type
 * @return cnet_act_func*
 */
cnet_act_func *cnet_get_act(enum cnet_act_type type);


/**
 * Get activation derivative function by type
 *
 * Returns a pointer to the activation function derivative.
 *
 * @param enum cnet_act_type: Activation type
 * @return cnet_act_func_dx*
 */
cnet_act_func_dx *cnet_get_act_dx(enum cnet_act_type type);


#endif /* CNET_ACTIVATION_H */
