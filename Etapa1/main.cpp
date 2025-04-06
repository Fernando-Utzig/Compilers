// Fernando Vieira Utzig - 00324861
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "symbols.hpp"
#include "tokens.h"

extern FILE* yyin;
extern int running;
extern int lineNumber;
extern char* yytext;
int yylex();
int isRunning(void);
int getLineNumber(void);
void initMe(void);
void printSymbolTable(void);

int main(int argc, char** argv) {
    int tok;
    if (argc < 2) {
        fprintf(stderr, "Call a.out filename\n");
        exit(1);
    }
    if (0 == (yyin = fopen(argv[1], "r"))) {
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        exit(1);
    }
    initMe();

    while (running) {
        tok = yylex();

        if (!running) break;
        switch (tok) {
            case KW_BYTE:           { fprintf(stderr,"KEYWORD_BYTE "); } break;
            case KW_INT:            { fprintf(stderr,"KEYWORD_INT "); } break;
            case KW_REAL:           { fprintf(stderr,"KEYWORD_REAL "); } break;
            case KW_IF:             { fprintf(stderr,"KEYWORD_IF "); } break;
            case KW_ELSE:           { fprintf(stderr,"KEYWORD_ELSE "); } break;
            case KW_DO:             { fprintf(stderr,"KEYWORD_DO "); } break;
            case KW_WHILE:          { fprintf(stderr,"KEYWORD_WHILE "); } break;
            case KW_READ:           { fprintf(stderr,"KEYWORD_READ "); } break;
            case KW_PRINT:          { fprintf(stderr,"KEYWORD_PRINT "); } break;
            case KW_RETURN:         { fprintf(stderr,"KEYWORD_RETURN "); } break;
            case OPERATOR_LE:       { fprintf(stderr,"OPERATOR_LE "); } break;
            case OPERATOR_GE:       { fprintf(stderr,"OPERATOR_GE "); } break;
            case OPERATOR_EQ:       { fprintf(stderr,"OPERATOR_EQ "); } break;
            case OPERATOR_DIF:      { fprintf(stderr,"OPERATOR_DIF "); } break;
            case TK_IDENTIFIER:     { fprintf(stderr,"IDENTIFIER %s ", yytext); } break;
            case LIT_INT:           { fprintf(stderr,"LIT_INT %s ", yytext); } break;
            case LIT_REAL:          { fprintf(stderr,"LIT_REAL %s ", yytext); } break;
            case LIT_CHAR:          { fprintf(stderr,"LIT_CHAR %s ", yytext); } break;
            case LIT_STRING:        { fprintf(stderr,"LIT_STRING %s ", yytext); } break;
            case TOKEN_ERROR:       { fprintf(stderr,"TOKEN_ERROR %s na linha %d ", yytext, lineNumber); } break;
            case '-':
            case ':':
            case '(':
            case ')':
            case '[':
            case ']':
            case '{':
            case '}':
            case '=':
            case '+':
            case '*':
            case '/':
            case '%':
            case '<':
            case '>':
            case '|':
            case '&':
            case '~':
            case ',':
                                    { fprintf(stderr, "%c ", yytext[0]); } break;
            case ';':               { fprintf(stderr, "%c \n", yytext[0]); } break;
            default:                { fprintf(stderr,"UNKNOWN OPERATOR %s ", yytext); } break;
        }
    }
    fprintf(stderr, "File had %d lines\n ", lineNumber);
    symbolPrintTable();
    return 0;
}