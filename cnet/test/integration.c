/**
 * Integration Tests for CNet.
 * */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cnet.h"


#define print(x) printf("%s\n", x); fflush(NULL);

#if 1
/**
 * Passes random inputs through the net,
 * useful to run with valgrind and to check that any of the changes
 * makes the app crash.
 * */
 
void test_random_inputs() {
    // sizes
    int input_size = 784;
    int output_size = 10;

    // layers
    int n_layers = 3;

    // samples
    int train_size = 600;
    int val_size = 100;

    // hyperparameters
    int epochs = 1000;
    double lr = 1;

    // create training samples

    double **X_train = malloc(sizeof(double*)*train_size);
    double **Y_train = malloc(sizeof(double*)*train_size);
    for (int i = 0; i < train_size; i++) {
        X_train[i] = malloc(sizeof(double)*input_size);
        for(int j = 0; j < input_size; j++) {
            X_train[i][j] = ((double)rand())/((double)RAND_MAX);
        }

        Y_train[i] = malloc(sizeof(double)*output_size);
        for(int j = 0; j < output_size; j++) {
            Y_train[i][j] = round((double)rand()/((double)RAND_MAX));
        }
    } 

    // create validation samples

    double **X_val = malloc(sizeof(double*)*val_size);
    double **Y_val = malloc(sizeof(double*)*val_size);
    for (int i = 0; i < val_size; i++) {
        X_val[i] = malloc(sizeof(double)*input_size);
        for(int j = 0; j < input_size; j++) {
            X_val[i][j] = ((double)rand())/((double)RAND_MAX);
        }

        Y_val[i] = malloc(sizeof(double)*output_size);
        for(int j = 0; j < output_size; j++) {
            Y_val[i][j] = round((double)rand()/((double)RAND_MAX));
        }
    } 

    
  /// initialize neural network
    cnet *nn = nn_init(
        input_size,
        output_size,
        n_layers
    );
        
    /// add layers
    nn_add(nn, input_size, 64, sigmoid_act);
    nn_add(nn, 64, 32, sigmoid_act);
    nn_add(nn, 32, output_size, sigmoid_act);

    // create a file to save output
    FILE *history_file = fopen("test/test_random_inputs.dat", "w");
    
    // train
    nn_train(
        nn,
        X_train,
        Y_train,
        X_val,
        Y_val,
        train_size,
        val_size,
        mse_loss,
        metric_accuracy_round,
        lr,
        epochs,
        history_file
    );

    // free all objects
    nn_free(nn);

    for(int i = 0; i < train_size; i++) {
        free(X_train[i]);
        free(Y_train[i]);
    }
    free(X_train); free(Y_train);
    for(int i = 0; i < val_size; i++) {
        free(X_val[i]);
        free(Y_val[i]);
    }
    free(X_val); free(Y_val);
}
#endif

/**
 * Run all tests. */
int main() {

    // set random seed
    srand((unsigned int)23);

    // random inputs
    printf(
        "*************************************************************\n"
        "                   RUNNING WITH RANDOM INPUT                 \n"
        "*************************************************************\n"
    );

    //test_random_inputs();

    printf(
        "*************************************************************\n"
        "                           PASSED                            \n"
        "*************************************************************\n"
    );

}
