/**
 * MNIST CNet Train Configuration
 * */

#ifndef MNIST_CFG_H
#define MNIST_CFG_H

/* OUTPUT PATHS */

#define HISTORY_FILE_PATH       "./out/history.dat"
#define CONF_FILE_PATH          "./out/conf_matrix.dat"
#define REPORT_FILE_PATH        "./out/report.txt"
#define MODEL_FILE_PATH         "./out/model.cnet"

#define WEIGHT_1_PATH         "./out/weight1.dat"
#define WEIGHT_2_PATH         "./out/weight2.dat"
#define WEIGHT_3_PATH         "./out/weight3.dat"

#define BIAS_1_PATH            "./out/bais1.dat"
#define BIAS_2_PATH            "./out/bias2.dat"
#define BIAS_3_PATH            "./out/bias3.dat"

#define CONDIT_BIAS  0
#define CONDIT_WEIGHT  1

/* DATASET PATHS */

#define TRAIN_IM_PATH           "./data/train-images.idx3-ubyte"
#define TRAIN_LABEL_PATH        "./data/train-labels.idx1-ubyte"
#define VAL_IM_PATH             "./data/t10k-images.idx3-ubyte"
#define VAL_LABEL_PATH          "./data/t10k-labels.idx1-ubyte"


/* DATA INFO */

#define INPUT_SIZE      784     // 28px*28px
#define OUTPUT_SIZE     10      // 10 digits
#define TRAIN_SIZE      60000   // training samples
#define VAL_SIZE        10000   // validation samples
#define INFO_IM_LEN     4       // number of information bytes in train file
#define INFO_LABEL_LEN  2       // number of information bytes in val file


#endif /* MNIST_CFG_H */
