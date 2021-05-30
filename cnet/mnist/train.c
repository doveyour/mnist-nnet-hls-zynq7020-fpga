/**
 * Train CNet on the MNist Dataset.
 */

#include <stdio.h>
#include "cnet.h"
#include "dataset.h"
#include "config.h"
int get_key_value_by_linef(char* path, char* key_str, double * val)
{
    FILE *fp;
    long file_len;
    char *str_buf = (char *)malloc(file_len + 1);
	char *pos;
	int i;
	double j;
    if((fp = fopen(path, "r+")) == NULL)
    {
        printf("open");
        return -1;
    }
    
    
    fseek(fp, 0, SEEK_END);    
    file_len = ftell(fp);      
    fseek(fp, 0, SEEK_SET);    

    
   while(fgets(str_buf, file_len, fp))     //
   {
        if(str_buf[0]=='#')//开头有#号跳过不读
        {	 
        	printf("#\n");
			continue; 
        }
		 if(strstr(str_buf, key_str) != NULL)//有
		 {
			int index= strlen(key_str);
			
			j = atof(&str_buf[index+1]);
			*val = j;
			free(str_buf);
			fclose(fp);
			return 1;
					 
		 }
	
	}
	
    free(str_buf);
    fclose(fp);

    return -2;
}

int get_key_value_by_line(char* path, char* key_str, int* val)
{
    FILE *fp;
    long file_len;
    char *str_buf = (char *)malloc(file_len + 1);
	char *pos;
    if((fp = fopen(path, "r+")) == NULL)
    {
        perror("open");
        return -1;
    }
    
    
    fseek(fp, 0, SEEK_END);    
    file_len = ftell(fp);      
    fseek(fp, 0, SEEK_SET);    

    
   while(fgets(str_buf, file_len, fp))     //
   {
        if(str_buf[0]=='#')//开头有#号跳过不读
        {
			continue; 
        }
		 if(strstr(str_buf, key_str) != NULL)//有
		 {
			int index= strlen(key_str);
			*val = atoi(&str_buf[index+1]);
			free(str_buf);
			fclose(fp);
			return 1;
					 
		 }
	
	}
	
    free(str_buf);
    fclose(fp);

    return -2;
}


int main() 
{
    // hyperparameters
    double lr =0.01 ;
    int epochs = 100;
    FILE *model_file;
    printf("train start\n");
    // define dataset variables
//int train_size = TRAIN_SIZE;
    int train_size = TRAIN_SIZE;

    int val_size = VAL_SIZE;

    // define input / output
    int output_size = OUTPUT_SIZE;
    int input_size = INPUT_SIZE;

    // load mnist dataset
    mnist_dataset *train_set = mnist_train_set(train_size);
    mnist_dataset *val_set = mnist_val_set(val_size);

    // init model
    int n_layers = 3;
    cnet *nn = nn_init(input_size,output_size, n_layers);

    /// add layers
    nn_add(nn,  input_size,     64,            sigmoid_act);
    nn_add(nn,  64,            32,            sigmoid_act);
    nn_add(nn,  32,            output_size,    sigmoid_act);

    // create a file to save output
    FILE *history_file = fopen(HISTORY_FILE_PATH, "w");

    // train
    nn_train(
        nn,
        train_set->images,
        train_set->labels,
        val_set->images,
        val_set->labels,
        train_set->size,
        val_set->size,
        mse_loss,
        metric_accuracy_argmax,
        lr,
        epochs,
        history_file
    );

    // save model
    model_file = fopen(MODEL_FILE_PATH, "w");
    nn_save( nn,model_file );
   //save several file
	//weight_1
	model_file = fopen(WEIGHT_1_PATH, "w");
        nn_save_con( nn,model_file,0, CONDIT_WEIGHT);

	model_file = fopen("./out/weight1__.dat", "w");
        nn_save_con2( nn,model_file,0, CONDIT_WEIGHT);
	//bias_1
	model_file = fopen(BIAS_1_PATH, "w");
	nn_save_con( nn,model_file,0, CONDIT_BIAS);

	//weight_2
	model_file = fopen(WEIGHT_2_PATH, "w");
	nn_save_con( nn,model_file,1, CONDIT_WEIGHT);

	model_file = fopen("./out/weight2__.dat", "w");
        nn_save_con2( nn,model_file,1, CONDIT_WEIGHT);
	//bias_2
	model_file = fopen(BIAS_2_PATH, "w");
	nn_save_con( nn,model_file,1, CONDIT_BIAS);

	//weight_3
	model_file = fopen(WEIGHT_3_PATH, "w");
	nn_save_con( nn,model_file,2, CONDIT_WEIGHT);

	model_file = fopen("./out/weight3__.dat", "w");
        nn_save_con2( nn,model_file,2, CONDIT_WEIGHT);
	//bias_3
	model_file = fopen(BIAS_3_PATH, "w");
	nn_save_con( nn,model_file,2, CONDIT_BIAS);

   //all
	model_file = fopen("./out/weight__.dat", "w");
        nn_save_con3( nn,model_file, CONDIT_WEIGHT);

	model_file = fopen("./out/bias__.dat", "w");
        nn_save_con3( nn,model_file, CONDIT_BIAS);
    // free all objects
    nn_free(nn);
    mnist_free(train_set);
    mnist_free(val_set);
    printf("train end\n");
    return 0;
}
