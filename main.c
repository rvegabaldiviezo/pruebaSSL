#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

int main(){

    char buffer[128];
    Token token = get_token(buffer);

    do{
        if(token == SEP){
            
            printf("separador: %s \n", buffer);           
        } 
        else if (token == CAD){
            
            printf("cadena: %s \n", buffer); 
        }
        
        token = get_token(buffer);

    }while( token != FDT);

    printf("Fin De Texto:");

    return 0;
}