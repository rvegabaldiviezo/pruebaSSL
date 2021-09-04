#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

int main(){

    char buffer[123];
    Token token = get_token(buffer);

    while( token != FDT){

        if(token == SEP){  printf("Separador: %s \n", buffer);           
        } 
        else if (token == CAD){ printf("Cadena: %s \n", buffer); 
        }
        token = get_token(buffer);
    }
    printf("Fin de texto: ");
    return 0;
}