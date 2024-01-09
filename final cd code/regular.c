//to recognize strings under 'a', 'a*b+', 'abb'
#include <stdio.h>
#include <string.h>

int main()
{
    int flag=1,i=0;
    char str[20];
    printf("Enter string: ");
    scanf("%s",str);

    if(strcmp(str,"a")==0)
    {    
        printf("String recognised under 'a' ");
        return 0;
    }
    else if(strcmp(str,"abb")==0)    
    {
        printf("String recognised under 'abb' ");
        return 0;
    }

    int a=1,b=1;
    while(a)
    {   
        if(str[i]!='a')
            a=0;
        else
            i++;
    }
    while(b && str[i]!='\0')
    {   
        if(str[i]!='b')
            b=0;
        else
            i++;
    }

    if(b)
        printf("String recognised under 'a*b+' ");
    else
        printf("Unrecognised");

    return 0;
}