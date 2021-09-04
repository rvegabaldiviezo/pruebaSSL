#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "scanner.h"

Token get_token(char *buffer)
{    
    int a = getchar();     

    while( isspace(a)) { a = getchar(); }

    if(a == ','){
        buffer[0]  = ','; buffer[1] = '\0';
        return SEP;
    }
    else if(a == EOF){   
        return FDT;
    }
    else{
        int p;    
        for (p = 0; !isspace(a) && !(a == ',') && !(a == EOF); p++){
            buffer[p] = a;
            a = getchar();  
        }
        buffer[p+1] = '\0';                     
        ungetc(a, stdin);
        return CAD; 
    }
}