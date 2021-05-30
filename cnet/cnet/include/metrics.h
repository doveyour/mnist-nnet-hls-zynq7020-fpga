/**
 * Metrics for CNet.
 */

#ifndef CNET_METRICS_H
#define CNET_METRICS_H


/* Available Types */

enum cnet_metric_type {
    metric_accuracy_round,
    metric_accuracy_argmax
};


/**
 * Metric function
 *
 * Computes the metric of a predicted output over the expected values.
 * Both array should have the same size.
 *
 * @param const double *pred: Predictions array
 * @param const double *real: Expected array
 * @param int size: Predictions/Expected size.
 */
typedef double cnet_metric_fun(
    double const *pred,
    double const *real,
    int size
);


/**
 * Get metric function
 * Given a metric type, returns a pointer to the function.
 *
 * @param enum cnet_metric_type: Metric Type
 */
cnet_metric_fun *cnet_get_metric(enum cnet_metric_type type);



#endif /* CNET_METRICS_H */
