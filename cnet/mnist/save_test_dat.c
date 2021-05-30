

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define INFO_IM_LEN     4       // number of information bytes in train file
#define INFO_LABEL_LEN  2       // number of information bytes in val file
#define VAL_IM_PATH             "./data/t10k-images.idx3-ubyte"
#define VAL_LABEL_PATH          "./data/t10k-labels.idx1-ubyte"
#define INPUT_SIZE      784     // 28px*28px
void mnist_read_data_image_file(
    char const *file_path1,char const *file_path2,
    int data_len
){
    // open file
    int file1,file2;
	int i,j,k,n;
	
    char filename[30];
	FILE *diff_file;
    if ((file1 = open(file_path1, O_RDONLY)) == -1)
	{
        printf("Failed to open file: %s", file_path1);
        exit(-1);
    }
	 if ((file2 = open(file_path2, O_RDONLY)) == -1)
	{
        printf("Failed to open file: %s", file_path2);
        exit(-1);
    }
	
    // read info array (we don't need this just now)
    int info_arr1[INFO_IM_LEN];
    read(file1, info_arr1, INFO_IM_LEN * sizeof(int));
    // read info array (we don't need this just now)
    int info_arr2[INFO_LABEL_LEN];
    read(file2, info_arr2, INFO_LABEL_LEN * sizeof(int));
	
    // read data
    // read image data and save name by label
    for( i = 0; i < data_len; i++)
	{
		memset(filename,0,sizeof(filename));
		n =0;
        unsigned char image_data[INPUT_SIZE];
	float image_data1[INPUT_SIZE];
	memset(image_data,0,sizeof(image_data));
	memset(image_data1,0,sizeof(image_data1));
        read(file1, &image_data, INPUT_SIZE * sizeof(unsigned char));
	unsigned char d;
        read(file2, &d, sizeof(unsigned char));
		// to save the name 
	
		memcpy(filename,"./out/",strlen("./out/"));
		sprintf(filename+strlen(filename),"%d%s%d",i,"_",d);
		
	        memcpy(filename+strlen(filename),".dat",strlen(".dat"));
		
		printf("save photo down image\n");
		printf("dir:%s\n",filename);
		
		if(NULL == (diff_file = fopen(filename, "w+")))
		{
			printf("Failed to open file: %s", filename);
      			 exit(-1);

		}
		
 		for(int j = 0; j < INPUT_SIZE; j++) 
		{
		  image_data1[j] =(float )image_data[j]; 
			
		}
		
	   for(int j = 0; j < INPUT_SIZE; j++) 
	   {
		   fprintf(diff_file, " %.6f", (float )image_data[j]/255.0);
		   fprintf(diff_file, "%s", ",");
		   fprintf(diff_file, "\n");
	   }

	for( k=0;k<28;k++)
	{

			for( j=0;j<28;j++)
			{
				printf("%.0f",((float )image_data[n++]/255.0));
			}
			printf("\n");

	}
	
	fclose(diff_file);
    }
}

int main(void)
{



 mnist_read_data_image_file(VAL_IM_PATH,VAL_LABEL_PATH,100);




return 0;
}

