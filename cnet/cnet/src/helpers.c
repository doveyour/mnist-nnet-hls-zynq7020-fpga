/**
 * Miscellaneous Helpers for CNet.
 */

#include <stdlib.h>
#include <math.h>
#include "helpers.h"


/// Array Helpers


/**
 * Array Sum */
double cnet_sum(double *arr, int size) {
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}


/**
 * Array Mean */
double cnet_mean(double *arr, int size) {
    return cnet_sum(arr, size) / size;
}


/**
 * Array random suffle
 * https://stackoverflow.com/questions/6127503/shuffle-array-in-c */
void cnet_shuffle(int *arr, int size) {
    if (size < 1) return;
    for (int i = 0; i < size - 1; i++) {
      int j = i + rand() / (RAND_MAX / (size - i) + 1);
      int t = arr[j];
      arr[j] = arr[i];
      arr[i] = t;
    }
}


/**
 * Idx Array */
int *cnet_idx(int size) {
    int *ret = malloc(sizeof(int)*size);
    for(int i = 0; i < size; i++)
	{
        ret[i] = i;
    }
    return ret;
}


/**
 * ArgMax */
double cnet_argmax(double const *arr, int size) {
    double max_idx = 0;
    for(int i = 1; i < size; i++) {
        if(arr[i] > arr[(int)max_idx]) {
            max_idx = i;
        }
    }
    return max_idx;
}


/**
 * Vector Dot Product */
double cnet_dot_vector(
    double const *x,
    double const *y,
    int size
){
    double res = 0;
    for(int i = 0; i < size; i++)
        res += x[i] * y[i];
    return res;
}


/**
 * Vector Matrix Dot Product */
void cnet_dot_mat(
    double *vector,
    double **matrix,
    int size
){
    // create the temporary vector to store the result
    double *temp = malloc(sizeof(double) * size);

    // compute the dot product
    for(int i = 0; i < size; i++)
        temp[i] = cnet_dot_vector(vector, matrix[i], size);

    // store the result and free
    for(int i = 0; i < size; i++)
        vector[i] = temp[i];
    free(temp);
}


/**
 * Vector Clipping */
void cnet_clip(
    double *vector,
    int size
){
    // compute the norm
    double norm = 0;
    for(int i = 0; i < size; i++)
        norm += pow(vector[i], 2); 
    norm = sqrt(norm);

    // clip the given vector using the norm
    for(int i = 0; i < size; i++)
        vector[i] = vector[i] / norm;
}
