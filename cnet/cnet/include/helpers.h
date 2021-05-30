/**
 * Miscellaneous Helpers for CNet.
 *
 * Contains several helper functions, to keep the cnet code cleaner.
 */

#ifndef CNET_HELPERS_H
#define CNET_HELPERS_H


#define non_zero(x) (x + 1e-10)


/// Array helpers


/**
 * Double Array Sum.
 * Performs the sum of an array.
 *
 * @param double *: The array
 * @param int: Array size
 * @return double: sum
 */
double cnet_sum(double *arr, int size);


/**
 * Double Array Mean.
 *
 * @param double *: The array
 * @param int: Array size
 * @return double: sum
 */
double cnet_mean(double *arr, int size);


/**
 * Random shuffle an array (in-place).
 *
 * @param double *: The array
 * @param int: Array size
 */
void cnet_shuffle(int *arr, int size);


/**
 * Idx Array
 *
 * Allocates and initialize an array with indexes
 * starting from 0 to given size.
 *
 * @param int: Size
 * @return int *: resulting array
 */
int *cnet_idx(int size);


/**
 * ArgMax
 *
 * Returns the index for the max element in a given array.
 *
 * @param double *arr;
 * @param int size: arr size
 * @return double: Index of max element (as double) 
 */
double cnet_argmax(double const *arr, int size);


/**
 * Vector Dot Product
 *
 * Performs a dot product between two vectors.
 *
 * @param double *: Vector A (n)
 * @param double *: Vector B (nxn)
 * @param int: Vector Size (n)
 * @return double: Result
 */
double cnet_dot_vector(
    double const *x,
    double const *y,
    int size
);


/**
 * Vector Matrix Dot Product
 *
 * Performs a dot product between a vector and a matrix.
 * Stores the result in the given vector (in-place).
 *
 * @param double *: Vector (n)
 * @param double **: Matrix (nxn)
 * @param int: Vector Size (n)
 */
void cnet_dot_mat(
    double *vector,
    double **matrix,
    int size
);


/**
 * Clipping
 *
 * Normalize the values of a given array using the vector norm.
 *
 * @param double *: Vector
 * @param int: Vector size
 */
void cnet_clip(
    double *vector,
    int size
);


#endif /* CNET_HELPERS_H */
