/**
 * CNet file management.
 *
 * Load & Save the CNet model from a given file.
 */

#include <stdlib.h>
#include "cnet.h"


/**
 * Save CNet into File. */
void nn_save(cnet const* nn,FILE *out)
{
    // save basic network info
    fprintf(out, "%d %d %d \n", nn->in_size, nn->out_size, nn->n_layers);

    // save every layer info
    for(int i = 0; i < nn->n_layers; i++)
	{
        clayer *layer = nn->layers[i];
        fprintf(
            out,
            "%d %d %d \n",
            layer->in_size,
            layer->out_size,
            layer->activation
        );

        // save every layer biases
        for(int j = 0; j < layer->out_size; j++) 
		{
            fprintf(out, " %.7f", layer->bias[j]);
        }
        fprintf(out, "\n");

        // save every layer weights
        for(int j = 0; j < layer->out_size; j++) 
		{
            for(int k = 0; k < layer->in_size; k++)
			{
                fprintf(out, " %.7f", layer->weights[j][k]);
            }
            fprintf(out, "\n");
        }
    }
}
/**
 * Save CNet into several File. */
void nn_save_con(cnet const* nn,FILE *out,int i,int condit)
{
    // save basic network info
    //fprintf(out, "%d %d %d \n", nn->in_size, nn->out_size, nn->n_layers);

    // save every layer info
   
        clayer *layer = nn->layers[i];
    
	    if(condit==0)
	   	{
	        // save one layer biases by condition
	        for(int j = 0; j < layer->out_size; j++) 
			{
	            fprintf(out, "%.7f", layer->bias[j]);
				fprintf(out, "%s", ",");
				fprintf(out, "\n");
	        }
	   	}
        // save one layer weights
        if(condit==1)
	   	{
	        for(int j = 0; j < layer->out_size; j++) 
			{
	            for(int k = 0; k < layer->in_size; k++)
				{
	                fprintf(out, "%.7f", layer->weights[j][k]);
					fprintf(out, "%s", ",");
					
	            }
	            fprintf(out, "\n");
	        }
        }
}
/**
 * Save CNet into several File. */
void nn_save_con2(cnet const* nn,FILE *out,int i,int condit)
{
    // save basic network info
    //fprintf(out, "%d %d %d \n", nn->in_size, nn->out_size, nn->n_layers);

    // save every layer info
   
        clayer *layer = nn->layers[i];
    
	    if(condit==0)
	   	{
	        // save one layer biases by condition
	        for(int j = 0; j < layer->out_size; j++) 
			{
	            fprintf(out, "%.7f", layer->bias[j]);
				fprintf(out, "%s", ",");
				fprintf(out, "\n");
	        }
	   	}
        // save one layer weights
        if(condit==1)
	   	{
	        for(int j = 0; j < layer->out_size; j++) 
			{
	            for(int k = 0; k < layer->in_size; k++)
				{
	                fprintf(out, "%.7f", layer->weights[j][k]);
					fprintf(out, "%s", ",");
					fprintf(out, "\n");
					
	            }
	            //fprintf(out, "\n");
	        }
        }
}
/**
 * Save CNet into several File. */
void nn_save_con3(cnet const* nn,FILE *out,int condit)
{
    // save basic network info
    //fprintf(out, "%d %d %d \n", nn->in_size, nn->out_size, nn->n_layers);
    // save every layer info
   for(int i=0;i<3;i++)
{
        clayer *layer = nn->layers[i];
    
	    if(condit==0)
	   	{
	        // save one layer biases by condition
	        for(int j = 0; j < layer->out_size; j++) 
			{
	            fprintf(out, "%.7f", layer->bias[j]);
				fprintf(out, "%s", ",");
				fprintf(out, "\n");
	        }
	   	}

        // save one layer weights
        if(condit==1)
	   	{
	        for(int j = 0; j < layer->out_size; j++) 
			{
	            for(int k = 0; k < layer->in_size; k++)
				{
	                fprintf(out, "%.7f", layer->weights[j][k]);
					fprintf(out, "%s", ",");
					fprintf(out, "\n");
					
	            }
	            //fprintf(out, "\n");
	        }
        }
}
}
/**
 * Load CNet from File. */
cnet *nn_load(
    FILE *in
){
    // load basic network info
    int in_size, out_size, n_layers;
    fscanf(in, "%d %d %d \n", &in_size, &out_size, &n_layers);

    // init cnet
    cnet *nn = nn_init(in_size, out_size, n_layers);

    for(int i = 0; i < nn->n_layers; i++) 
	{
        // load layer info
        int in_size, out_size;
        enum cnet_act_type act_type;
        fscanf(
            in,
            "%d %d %d \n",
            &in_size,
            &out_size,
            &act_type
        );

        // create layer
        nn_add(nn,in_size,out_size,act_type);
        clayer *layer = nn->layers[i];

        // load biases
        for(int j = 0; j < layer->out_size; j++) 
		{
            fscanf(in, " %lf", &(layer->bias[j]));
        }
        fscanf(in, "\n");

        // load weights
        for(int j = 0; j < layer->out_size; j++)
		{
            for(int k = 0; k < layer->in_size; k++) {
                fscanf(in, " %lf", &(layer->weights[j][k]));
        }
            fscanf(in, "\n");
        }
    }

    return nn;
}
