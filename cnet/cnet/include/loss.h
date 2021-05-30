/*****************************************************************************
 *                                  LOSS
 * Defines the available loss functions and some helpers to work with.
 ****************************************************************************/

#ifndef CNET_LOSS_H
#define CNET_LOSS_H


enum cnet_loss_type {
    mse_loss,                   // Mean Squared Error
    cross_entropy_loss          // Cross Entropy Loss
};


/**
 * Loss function
 *
 * The loss function will return a number, since it will not be used 
 * to train the model, but for visualization purposes only.
 *
 * @param double *: Prediction
 * @param double *: Target
 * @param int : size
 * @return double
 */
typedef double cnet_loss_func(
    double const *,
    double const *,
    int
);


/**
 * Loss function derivative.
 *
 * The loss function derivative will compute the derivative for each
 * of the predictions and will populate the given array with these values.
 * This will be used to compute the layer's delta, which then allow us
 * to update the weights.
 *
 * @param double *: Prediction
 * @param double *: Target
 * @param double *: Destination array
 * @param int: Size of the given arrays
 */
typedef void cnet_loss_func_dx(
    double const *,
    double const *,
    double *,
    int
);


/**
 * Get Loss
 * Returns the loss function pointer, dependending on the loss type.
 *
 * @param cnet_loss_type
 * @return cnet_loss_func
 */
cnet_loss_func *cnet_get_loss(enum cnet_loss_type type);


/**
 * Get Loss Derivative
 * Returns the loss function derivative pointer, dependending on the loss type.
 *
 * @param cnet_loss_type
 * @return cnet_loss_func_dx
 */
cnet_loss_func_dx *cnet_get_loss_dx(enum cnet_loss_type type);


#endif /* CNET_LOSS_H */
