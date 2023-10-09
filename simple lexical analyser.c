#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_string(char *str,int *length,int typ,int lin)
{
	if(*length>0)
	{
		printf("%.*s\t%s\t",*length,str,(typ==1)?"identifier":"constant");
		printf("%d\n",lin);
		*length=0;
	}
}

int check_indentifier(char *str,int *length,int lin)
{
	if(strncmp(str, "int", 3)==0)
	{
		printf("int\tkeyword \t%d\n",lin);
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
	int length=0,line=1;
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
				print_string(str,&length,typ,line);
    			printf("%c\toperator\t%d\n",cd[forward++],line);
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
				print_string(str,&length,typ,line);
    			printf("%c\tpunctuation\t%d\n",cd[forward++],line);
    			begin++;
    			continue;
    		}
    		else if(cd[forward]==' ' || cd[forward]=='\n')
    		{
				if (cd[forward]=='\n')
					line++;
				if(!check_indentifier(str,&length,line))
					print_string(str,&length,typ,line);
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
