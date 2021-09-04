#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

typedef enum{ FDT, SEP, CAD } Token ;

Token get_token(char *buffer);

#endif