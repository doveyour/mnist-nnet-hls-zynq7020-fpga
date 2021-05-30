/*****************************************************************************
 *                                CNET
 * This section describes the neural network as a struct (`cnet`)
 * and defines several methods (starting with `nn_`) to interact with it.
 ****************************************************************************/

#ifndef CNET_H
#define CNET_H

#include <stdio.h>
#include "activation.h"
#include "loss.h"
#include "metrics.h"


struct cnet;
struct clayer;


typedef struct cnet {

    /* input/output dimensions */
    int in_size, out_size;

    /* layer helpful indices */
    int n_layers, last_layer;

    /* layers */
    struct clayer **layers;

} cnet;


typedef struct clayer {

    /* input/output dimensions */
    int in_size, out_size;

    /* activation type */
    enum cnet_act_type activation; 

    /* trainable parameters */
    double **weights;
    double *bias;

    /* output */
    double *output;

    /* delta (backprop purposes) */
    double *delta;

} clayer;



/**
 * Create cnet.
 *
 * Allocs the necessary memory for the network.
 *
 * @param int in_size: Input size
 * @param int out_size: Output size
 * @param int n_layers: Number of layers that should be allocated.
 * @return cnet *: Pointer to the allocated structure.
 */
cnet *nn_init(int in_size, int out_size,int n_layers);


/**
 * Free cnet.
 *
 * @param cnet *nn: cnet
 */
void nn_free(
    cnet *nn
);


/**
 * Add a Layer to the cnet.
 *
 * Assumes that the nn_init method was called, and all cnet* attributes
 * are correctly initialized.
 * The weights for the layer will be initialized with uniform
 * random numbers between 0 and 1.
 * Will assert if there is any inconsistency when adding a new layer.
 *
 * @param cnet *nn: cnet
 * @param int in_size: Input size for the new layer
 * @param int out_size: Output size for the new layer
 * @param cnet_act_type activation: Activation type for the new layer.
 */
void nn_add(
    cnet *nn,
    int in_size,
    int out_size,
    enum cnet_act_type activation
);


/**
 * CNet Prediction. 
 *
 * @param const cnet *nn: cnet
 * @param const double *X: Input (sized nn->in_size)
 * @return const double *: Pointer to results (sized nn->out_size)
 */
const double *nn_predict(
    cnet const *nn,
    double const *X
);


/**
 * Train the network.
 *
 * Performs backward passes through the net using SGD (single training sample)
 * It shuffles (in-place) the X and Y in every epoch to achieve better results.
 *
 * @param const cnet *nn: cnet
 * @param double const** X_train: Train Inputs
 * @param double const** Y_train: Train Expected output
 * @param double const** X_val: Val Inputs
 * @param double const** Y_val: Val Expected output
 * @param int train_size: Number of training samples
 * @param int val_size: Number of validation samples
 * @param cnet_loss_type loss_type: Cost function type
 * @param cnet_metric_type metric_type: Metric type to use
 * @param double learning_rate: Learning rate
 */
void nn_train(
    cnet const *nn,
    double **X_train,
    double **Y_train,
    double **X_val,
    double **Y_val,
    int train_size,
    int val_size,
    enum cnet_loss_type loss_type,
    enum cnet_metric_type metric_type,
    double learning_rate,
    int epochs,
    FILE *history_file
);


/**
 * Load the network from FILE.
 *
 * Initializes and reads the network weights from the given FILE.
 * The FILE must follow the given structure, or else this function will return
 * a corrupt nn and maybe even crash when being fred.
 *
 * @param FILE: network saved file.
 * @return cnet *: cnet
 */
cnet *nn_load(
    FILE *in
);


/**
 * Save the network into FILE.
 *
 * Saves the given network into a file, following the following structure:
 * in_size out_size n_layers
 * layer_in_size layer_out_size layer_act_type
 * layer_bias ...
 * layer_weights ...
 * ...
 *
 * @param cnet *nn: cnet
 * @param FILE out: output file
 */
void nn_save(
    cnet const *nn,
    FILE *out
);


void nn_save_con(cnet const* nn,FILE *out,int i,int condit);

void nn_save_con2(cnet const* nn,FILE *out,int i,int condit);
void nn_save_con3(cnet const* nn,FILE *out,int condit);

#endif /* CNET_H */
