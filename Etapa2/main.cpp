// Fernando Vieira Utzig - 00324861
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "symbols.hpp"
#include "parser.hpp"

extern FILE* yyin;
extern int running;
extern int lineNumber;
extern char* yytext;
int yylex();
int isRunning(void);
extern int getLineNumber(void);
extern void initMe(void);
extern void printSymbolTable(void);
extern int yyparse();

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Call a.out filename\n");
        exit(1);
    }
    if (0 == (yyin = fopen(argv[1], "r"))) {
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        exit(1);
    }

    initMe();

    int result = yyparse();
    fprintf(stderr, "File had %d lines\n", getLineNumber());

    fclose(yyin);

    if (result == 0) {
        fprintf(stderr, "File parsed successfully!\n");
        symbolPrintTable();
        exit(0);
    } else {
        fprintf(stderr, "File parsing failed.\n");
        exit(3);
    }

    return result;
}