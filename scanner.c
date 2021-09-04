#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "scanner.h"

Token token;

Token get_token(char *buffer)
{
    int a = getchar();     

    while(isspace(a))
    {
        a = getchar();   
    }
    if(a == ',')
    {
        token = SEP;
        buffer[0]  = ','; buffer[1] = '\0';
    }else if(a == EOF)
    {   
        token = FDT;
        buffer[0] = ' '; buffer[1] = '\0';
    }else if(!isspace(a) && !(a == ',') && !(a == EOF))
    {
        token = CAD;
        int p;    
        for (p = 0; !isspace(a) && !(a == ',') && !(a == EOF); p++)
        {
            buffer[p] = a;
            a = getchar();  
        }
        buffer[p+1] = '\0';                     
        ungetc(a, stdin); 
    }
    return token;
}