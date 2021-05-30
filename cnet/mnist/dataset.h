/**
 * Read the MNIST Dataset into a struct for CNet usage.
 * Taken from:
 *    Takafumi Hoiruchi. 2018.
 *    https://github.com/takafumihoriuchi/MNIST_for_C
 * Modified a little bit to fit my code style and requirements
 * (needed dynamically allocated arrays and stuff)
*/

#ifndef MNIST_DATASET_H
#define MNIST_DATASET_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "config.h"


// mnist dataset structure

typedef struct mnist_dataset {
    int size;
    double **images;
    double **labels;
} mnist_dataset;


// file parse functions

void mnist_read_data_image_file(
    char const *file_path,
    double **data,
    int data_len
){
    // open file
    int file;
	int i,j;
    if ((file = open(file_path, O_RDONLY)) == -1)
	{
        printf("Failed to open file: %s", file_path);
        exit(-1);
    }

    // read info array (we don't need this just now)
    int info_arr[INFO_IM_LEN];
    read(file, info_arr, INFO_IM_LEN * sizeof(int));

    // read image data
    for( i = 0; i < data_len; i++) {
        unsigned char image_data[INPUT_SIZE];
        read(file, &image_data, INPUT_SIZE * sizeof(unsigned char));
        for(j = 0; j < INPUT_SIZE; j++) {
            data[i][j] = (double)image_data[j] / 255.0;
            assert(
                data[i][j] >= 0 &&
                data[i][j] <= 1
            );
        }
    }
}


// init and free functions


void mnist_read_data_label_file(
    char const *file_path,
    double **data,
    int data_len
){
    // open file
    int file;
	int i,j;
    if ((file = open(file_path, O_RDONLY)) == -1) {
        printf("Failed to open file: %s", file_path);
        exit(-1);
    }

    // read info array (we don't need this just now)
    int info_arr[INFO_LABEL_LEN];
    read(file, info_arr, INFO_LABEL_LEN * sizeof(int));

    // read data
    for( i = 0; i < data_len; i++) {
        unsigned char d;
        read(file, &d, sizeof(unsigned char));
        for( j = 0; j < OUTPUT_SIZE; j++) {
            data[i][j] = d == ((unsigned char)j) ? 1 : 0;
        }
    }
}


mnist_dataset *mnist_init( int size,char const *image_file_path,char const *label_file_path)
{   int i;
    // alloc dataset struct
    mnist_dataset *ds = malloc(sizeof(mnist_dataset));

    // init basic info
    assert(size <= VAL_SIZE || size <= TRAIN_SIZE);
    ds->size = size;

    // alloc data arrays
    ds->images = malloc(sizeof(double *)*size);
    ds->labels = malloc(sizeof(double *)*size);
    for( i = 0; i < size; i++)
	{
        ds->images[i] = malloc(sizeof(double)*INPUT_SIZE);
        ds->labels[i] = malloc(sizeof(double)*OUTPUT_SIZE);
    }

    // read train images
    mnist_read_data_image_file(image_file_path,ds->images,ds->size );

    // read train labels
    mnist_read_data_label_file(label_file_path,ds->labels,ds->size);

    return ds;
}


void mnist_free(
    mnist_dataset *ds
){
	int i;

    // free data arrays
    for( i = 0; i < ds->size; i++) {
        free(ds->images[i]);
        free(ds->labels[i]);
    }
    free(ds->images);
    free(ds->labels);

    // free struct
    free(ds);
}


// train and val set


mnist_dataset *mnist_train_set(int size)
{
 	return mnist_init( size, TRAIN_IM_PATH, TRAIN_LABEL_PATH);
}


mnist_dataset *mnist_val_set(int size)
{
    return mnist_init(size,VAL_IM_PATH,VAL_LABEL_PATH );
}


#endif /* MNIST_DATASET_H */
