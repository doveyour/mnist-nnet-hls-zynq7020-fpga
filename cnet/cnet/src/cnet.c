/**
 * CNet Implementation
 *
 * Implements an Artificial Neural Network and several methods to work with.
 */

#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include "cnet.h"
#include "loss.h"
#include "activation.h"
#include "helpers.h"
#include "metrics.h"
#include "pbar.h"

#define INIT_BIAS 0
#define INIT_WEIGHT ((double)rand() / (RAND_MAX)) - 0.5

/**
 * Create CNet. */
cnet *nn_init(int in_size,int out_size, int n_layers)
{
    cnet *nn = malloc(sizeof(cnet));
    nn->in_size = in_size;
    nn->out_size = out_size;
    nn->n_layers = n_layers;
    nn->layers = malloc(sizeof(clayer*) * n_layers);
    nn->last_layer = 0;
    return nn;
}


/**
 * Free CNet. */
void nn_free(cnet *nn)
{
    for(int i = 0; i < nn->n_layers; i++) 
	{
        struct clayer *layer = nn->layers[i];
        for(int j = 0; j < layer->out_size; j++)
            free(layer->weights[j]);

        free(layer->weights);
        free(layer->bias);
        free(layer->output);
        free(layer->delta);
        free(layer);
    }
    free(nn->layers);
    free(nn);
}


/**
 * Add a Layer to the CNet. */
void nn_add(cnet *nn,int in_size,int out_size,enum cnet_act_type activation)
{
    // check the input/output size
    assert(nn->last_layer == 0 || in_size == nn->layers[nn->last_layer - 1]->out_size);
    assert(nn->last_layer < nn->n_layers - 1 || out_size == nn->out_size);

    // alloc the layer
    struct clayer* layer = malloc(sizeof(clayer));
    layer->in_size = in_size;
    layer->out_size = out_size;
    layer->activation = activation;

    layer->weights = malloc(sizeof(double*)*layer->out_size);
    layer->bias = malloc(sizeof(double)*layer->out_size);
    layer->output = malloc(sizeof(double)*layer->out_size);
    layer->delta = malloc(sizeof(double)*layer->out_size);

    // randomize weights and biases between 0 and 1
    for(int i = 0; i < layer->out_size; i++) {
        layer->bias[i] = INIT_BIAS;
        layer->weights[i] = malloc(sizeof(double)*layer->in_size);
        for(int j = 0; j < layer->in_size; j++)
            layer->weights[i][j] = INIT_WEIGHT;
    }

    // add layer to the net
    assert(nn->last_layer < nn->n_layers);
    nn->layers[nn->last_layer++] = layer;
}


/**
 * CNet Forward Pass
 *
 * Simply passes a given input (with expected size) through the net.
 * Does not return the result pointer, this should be accessed through
 * the nn->layers[last_layer - 1]->result;
 *
 * @param cnet const *nn: CNet
 * @param double const *X: Input (sized nn->in_size)
 */
void nn_forward( cnet const *nn,double const *X)
{
    double const *in = X;

    // pass through every layer in the net
    for(int i = 0; i < nn->n_layers; i++) 
	{
        struct clayer *layer = nn->layers[i];

        // pass through every neuron in the net
        for(int k = 0; k < layer->out_size; k++) 
		{
            // compute z for neuron
            double z = 0;
            for(int j = 0; j < layer->in_size; j++)
                z += layer->weights[k][j] * in[j];
            
            z += layer->bias[k];
            layer->output[k] = z;
        }

        // activate the layer output
        cnet_act_func *activate = cnet_get_act(layer->activation);
        activate(layer->output, layer->out_size);

        // set input for next layer
        in = layer->output;
    }
}


/**
 *
 * CNet Backward Pass
 *
 * Performs a single backpropagation step, using SGD, hence
 * it only takes one train sample.
 *
 * @param cnet const *nn: CNet
 * @param double *X: Input (sized nn->in_size)
 * @param double *Y: Expected output (sized nn->out_size)
 * @param cnet_loss_type: Loss type to use
 * @param double learning_rate: Learning Rate
 */
void nn_backward(cnet const *nn,double *X,double *Y,enum cnet_loss_type loss_type,double learning_rate)
{
    for(int l = nn->n_layers; l-->0;)
	{

        struct clayer* layer = nn->layers[l];
        struct clayer* next = l < (nn->n_layers - 1) ? nn->layers[l + 1] : NULL;
        struct clayer* previous = l > 0 ? nn->layers[l - 1] : NULL;

        // we start by computing the derivative of the loss
        // over the current output and saving it in the layer's delta
        if (!next) 
		{
            // this is the output layer,
            // we need to compute the loss over the network's output
            cnet_loss_func_dx *loss_dx = cnet_get_loss_dx(loss_type);
            loss_dx(layer->output,Y,layer->delta,layer->out_size);
        } 
		else 
		{
            // we need to compute the derivative of the cost over the current
            // activation output using the previously computed delta, along
            // with the dependencies of these values for the current layer
            // activation output and weights.
            for(int k = 0; k < layer->out_size; k++) 
			{
                double delta = 0;
                for(int j = 0; j < next->out_size; j++)
                    delta += next->delta[j] * next->weights[j][k];

                layer->delta[k] = delta;
            }
        }

        // get the activation derivative function, to update the layers delta
        cnet_act_func_dx *act_dx = cnet_get_act_dx(layer->activation);

        // layer's input: the Z derivative over the weights
        double *input = !previous ? X : previous->output;

        // update trainable parameters
        for(int k = 0; k < layer->out_size; k++)
		{
            // compute final delta using the activation derivative
            layer->delta[k] *= act_dx(layer->output[k]);

            // comput the neccessary update for the layer
            double update = learning_rate * layer->delta[k];

            // update bias
            layer->bias[k] -= update;

            // update weights
            for(int j = 0; j < layer->in_size; j++)
                layer->weights[k][j] -= update * input[j];
        }
    }
}


/**
 * CNet Prediction. */
const double *nn_predict(cnet const *nn,double const *X)
{
    // pass the input through the net
    nn_forward(nn, X);

    // return the output for the last layer
    return nn->layers[nn->n_layers - 1]->output;
}


/**
 * CNet Train Algorithm */
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
){
    // check nn initialization
    assert(nn->last_layer == nn->n_layers);
    assert(nn->layers[nn->last_layer - 1]->out_size == nn->out_size);
    assert(nn->layers[0]->in_size == nn->in_size);

    // init history file
    fprintf(history_file, "train_loss val_loss train_acc val_acc\n");

    // init temporary helper arrays
    int *idx_arr = cnet_idx(train_size);

    // init functions
    cnet_loss_func *loss = cnet_get_loss(loss_type);
    cnet_metric_fun *metric = cnet_get_metric(metric_type);

    for(int epoch = 0; epoch < epochs; epoch++)
	{
        double train_loss = 0, val_loss = 0; 
        double train_metric = 0, val_metric = 0;

        // shuffle the training set
        cnet_shuffle(idx_arr, train_size);

        // epoch training
        // SGD - batch size 1
        for(int s = 0; s < train_size; s++)
		{
            int sample = idx_arr[s];

            // update progress bar
            cnet_pbar_update(epoch,epochs,s,train_size);

            // pass the training sample through the net
            double const *train_pred = nn_predict(nn, X_train[sample]);

            // compute training loss and metric
            train_loss += loss(train_pred,Y_train[sample],nn->out_size);
			// compute 预测准确值

            train_metric += metric(train_pred, Y_train[sample],nn->out_size);

            // backprop step
            nn_backward(nn,X_train[sample],Y_train[sample],loss_type,learning_rate );
        }

        // epoch validation
        for(int s = 0; s < val_size; s++) 
		{
            // pass the training sample through the net
            double const *val_pred = nn_predict(nn, X_val[s]);

            val_loss += loss( val_pred, Y_val[s],nn->out_size);

            val_metric += metric(val_pred, Y_val[s],nn->out_size);
        } 

        // log metrics
        printf(
            "\n"
            "Train Loss: %lf "
            "- Train Accuracy: %lf "
            "- Val Loss: %lf "
            "- Val Accuracy: %lf \n",
            train_loss / train_size,
            train_metric / train_size,
            val_loss / val_size,
            val_metric / val_size
        );

        // save history
        fprintf(
            history_file,
            "%.20e %.20e %.20e %.20e\n",
            train_loss / train_size,
            val_loss / val_size,
            train_metric / train_size,
            val_metric / val_size
        );
    }
    free(idx_arr);
}
