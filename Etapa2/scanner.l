%{
/* Fernando Vieira Utzig - 00324861 */

#include "symbols.hpp"
#include "parser.hpp"
#include <string>

int lineNumber = 1;
int running = 1;

// Declaração da função symbolInsert 
extern SYMBOL *symbolInsert(int type, const char *text);

extern int yylex();
extern int yyparse();

// Função auxiliar para inverter um literal numérico
std::string reverseLiteral(const char *text) {
  int len = strlen(text);
  std::string reversed(len, ' '); // Inicializa a string com o tamanho correto
  for (int i = 0; i < len; i++) {
      reversed[i] = text[len - 1 - i];
  }
  return reversed;
}

%}

%option nounput
%option noinput
%x COMMENT

%%


"byte"                          { return KW_BYTE; }
"int"                           { return KW_INT; }
"real"                          { return KW_REAL; }
"if"                            { return KW_IF; }
"else"                          { return KW_ELSE; }
"do"                            { return KW_DO; }
"while"                         { return KW_WHILE; }
"read"                          { return KW_READ; }
"print"                         { return KW_PRINT; }
"return"                        { return KW_RETURN; }

"<="                            { return OPERATOR_LE; }
">="                            { return OPERATOR_GE; }
"=="                            { return OPERATOR_EQ; }
"!="                            { return OPERATOR_DIF; }

[a-zA-Z_]([a-zA-Z_]|[0-9])*     { symbolInsert(TK_IDENTIFIER, yytext); return TK_IDENTIFIER; }

[0-9]+                          { std::string reversed = reverseLiteral(yytext); symbolInsert(LIT_INT, reversed.c_str()); return LIT_INT; }
[0-9]+\/[0-9]+                  { symbolInsert(LIT_REAL, yytext); return LIT_REAL; }
\'[^\']\'                       { symbolInsert(LIT_CHAR, yytext); return LIT_CHAR; }
\"([^\"\\]|\\\"|\\\\|\\n)*\"    { symbolInsert(LIT_STRING, yytext); return LIT_STRING; }

[-;:\(\)\[\]\{\}=+*\/%\<\>\|&~,]       { return yytext[0]; }

[ \t]+                          { /* Ignora espaços e tabulações */ }
\n                              { lineNumber++; }


"//".*                          { /* Ignora comentário de linha única */ }
"/--"                           { BEGIN(COMMENT); }
<COMMENT>\n                     { lineNumber++; }
<COMMENT>"--/"                  { BEGIN(INITIAL); }
<COMMENT>.                      { /* Ignora o conteúdo do comentário */ }

.                               { return TOKEN_ERROR; }

<<EOF>>                         { running = 0; return 0; }


%%

int getLineNumber(void) {
  return lineNumber;
}

int isRunning(void) {
  return running;
}

int yywrap()
{
    running = 0;
    return 1;
}


