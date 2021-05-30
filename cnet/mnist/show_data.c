

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(int argc,char **argv[])
{

	FILE *diff_file;
	int file1,j,n;
	float info_arr1[784];
	n = 0;	
	printf("try to open file: %s\n", argv[1]);
	diff_file = fopen(argv[1], "r");
	
	
	for( j=0;j<783;j++)
	{
    		fscanf(diff_file, " %lf", &info_arr1[j]);
	}
	for( j=0;j<28;j++)
	{
		for( j=0;j<28;j++)
		{
			printf("%.0f",info_arr1[n++]);
		}
		printf("\n");

	}	


return 0;
}


	
