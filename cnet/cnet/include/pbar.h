/*****************************************************************************
 *                                  PBAR 
 * Progress Bar for CNet training progress.
 * Taken from:
 * https://stackoverflow.com/a/36315819/8189455
 ****************************************************************************/

#ifndef CNET_PBAR
#define CNET_PBAR

#include <stdio.h>

#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60


/**
 * Progress Bar Progress
 *
 * Calculates the sample percentage and updates a progress bar,
 * flushed to stdout. Also shows the current loss
 *
 * @param int sample: the number of samples used
 * @param int set_size: the total number of samples that should be used
 */
void cnet_pbar_update(int epoch,int total_epochs,int sample,int set_size)
{
    double percentage = (double)sample / set_size;
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf(
        "\r[EPOCH %d/%d] \t %3d%% [%.*s%*s]",
        epoch,
        total_epochs,
        val,
        lpad,
        PBSTR,
        rpad,
        ""
    );
    fflush(stdout);
}


#endif /* CNET_PBAR */
