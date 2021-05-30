/**
 * Metric Functions for CNet.
 */


#include <math.h>
#include "metrics.h"
#include "helpers.h"


double accuracy_round(double const *pred,double const *real,int size)
{
    double res = 0;
    for(int i = 0; i < size; i++) 
	{
        res += round(pred[i]) == round(real[i]);
    }
    return res / size;
}


double accuracy_argmax(
    double const *pred,
    double const *real,
    int size
){
    double pred_max = cnet_argmax(pred, size);
    double real_max = cnet_argmax(real, size);
    return pred_max == real_max ? 1 : 0;
}


/// getters


cnet_metric_fun *cnet_get_metric(enum cnet_metric_type type) {
    switch(type) {
        case metric_accuracy_round: 
			return accuracy_round;
        case metric_accuracy_argmax:
			return accuracy_argmax;
    }
	return 0;
}


const char *cnet_get_metric_name(enum cnet_metric_type type) {
    switch(type) {
        case metric_accuracy_round: return "Accuracy";
        case metric_accuracy_argmax: return "Accuracy";
    }
	return 0;
}