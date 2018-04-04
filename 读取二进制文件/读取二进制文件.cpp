#include<stdio.h>

int main()
{
    FILE *fp1=fopen("test.jpg","rb");
    //FILE *fp1=fopen("test.bmp","rb");
    //FILE *fp1=fopen("test.png","rb");
    //FILE *fp1=fopen("test.gif","rb");
    //FILE *fp1=fopen("test.ico","rb");
    
    FILE *fp2=fopen("result.txt","w");
    unsigned char temp;
    unsigned int sum=0; 
    fprintf(fp2,"{");
    int first_time=0;  
    while(fscanf(fp1,"%c",&temp)!=EOF)
    {
          if(first_time==0)
          {
               first_time=1;  
          }
          else
          {
              fprintf(fp2,",");
          }
          fprintf(fp2,"0x");
          fprintf(fp2,"%02x",temp);
          sum++;                                   
    }
    fprintf(fp2,"};");
    fprintf(fp2,"\n");
    fprintf(fp2,"sum:%u",sum);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
