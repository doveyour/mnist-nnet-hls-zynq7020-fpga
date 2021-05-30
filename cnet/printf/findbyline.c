#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*获取文件总行数
每行字符不超过N个超过就为一行
最长超过int
*/

int print_value_by_linef(char* path)
{
    FILE *fp;
    long file_len;
    char *str_buf = (char *)malloc(file_len + 1);
	char *pos;
	int i=27;
	int j=27;
    if((fp = fopen(path, "r+")) == NULL)
    {
        printf("open\n");
        return -1;
    }
    
    
    fseek(fp, 0, SEEK_END);    
    file_len = ftell(fp);      
    fseek(fp, 0, SEEK_SET);    

    
   while(i--)     //
   {
	    //printf("whilei\n");
		j = 28;
	    while(j--) 
		{
			//printf("whilej\n");
			fgets(str_buf,10, fp);
			printf("%c",str_buf[0]);
		
		}
		
			printf("\n");
			
	
	}
	
    free(str_buf);
    fclose(fp);

    return 1;
}

int main()
{ 
int i,j;
double k;
//printf("get_file_line:%d\n",get_file_line("./out/model.cfg"));
		
       
		if(1 == print_value_by_linef("./4t.dat"))
		{
			printf("sucess\n");
		}
		else
		{
			printf("erro\n");
			
		}
		return 0;
}

