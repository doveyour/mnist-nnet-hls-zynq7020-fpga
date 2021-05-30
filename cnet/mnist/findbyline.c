#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*获取文件总行数
每行字符不超过N个超过就为一行
最长超过int
*/
int get_file_line(char* path)
{
	 
         FILE *fp;  
         int n = 0; 
         int ch; 

         if((fp = fopen(path,"r+")) == NULL) 
         { 
             printf("open file 1.c error!\n"); 
         } 

         while((ch = fgetc(fp)) != EOF)
         { 
             if(ch == '\n') 
             { 
                 n++; 
             }
         } 

         fclose(fp);
         
         return n+1;	
}
int get_key_value_by_line(char* path, char* key_str, int * val)
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

int main()
{ 
int i,j;
double k;
printf("get_file_line:%d\n",get_file_line("./out/model.cfg"));
		
        if(1 == get_key_value_by_line("./out/model.cfg", "net", &i ))
		{
			printf("i1=:%d\n",i);
		}
		else
		{
			printf("erro");
			
		}
		if(1 == get_key_value_by_linef("./out/model.cfg", "learnrate",&k))
		{
			printf("i2=:%lf\n",k);
		}
		else
		{
			printf("erro");
			
		}
		return 0;
}

