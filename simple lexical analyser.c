#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_string(char *str,int *length,int typ)
{
	if(*length>0)
	{
		printf("%.*s\t%s\n",*length,str,(typ==1)?"identifier":"constant");
		*length=0;
	}
}

int check_indentifier(char *str,int *length)
{
	if(strncmp(str, "int", 3)==0)
	{
		printf("int\tkeyword\n");
		*length=0;
		return 1;
	}
	return 0;
}

//key,idn,oper,pun,cons
void main()
{
	char cd[100];
	char str[20];
	int length=0;
	int typ;
	
	FILE* fptr; 
    fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        printf("The file is not opened");
        exit(0);
    }	
    else
    {
    	int begin=0,forward=0,line=1;
    	while(cd[forward]!=EOF)
    	{
    		cd[begin]=getc(fptr);
    		if (cd[forward]=='=' || cd[forward]=='+')
    		{
				print_string(str,&length,typ);
    			printf("%c\toperator\n",cd[forward++]);
    			begin++;
    			continue;
    		}
    		
    		else if(cd[forward]>='0' && cd[forward]<='9')
    		{	
				typ=0;
				str[length++]=cd[forward++];
    			begin++;
    			continue;
    		}
    		
    		else if(cd[forward]>='a' && cd[forward]<='z')
    		{
				typ=1;
				str[length++]=cd[forward++];
    			begin++;
    			continue;
    		}
    		else if(cd[forward]==';')
    		{	
				print_string(str,&length,typ);
    			printf("%c\tpunctuation\n",cd[forward++]);
    			begin++;
    			continue;
    		}
    		else if(cd[forward]==' ' || cd[forward]=='\n')
    		{
				if(!check_indentifier(str,&length))
					print_string(str,&length,typ);
    			forward++;
    			begin++;
    			continue;
    		}
    		else
    		{
    			break;
    			forward++;
    			begin++;
    		}
    	}
    }

    fclose(fptr);
    printf("\n");
}
