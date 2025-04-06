// Fernando Vieira Utzig - 00324861
//
// symbols.hpp - tabela de símbolos
#ifndef SYMBOLS_HPP
#define SYMBOLS_HPP

#include <string>

using namespace std;

enum SymbolType {
    SYMBOL_INVALID,
    SYMBOL_ZEROS,
    SYMBOL_ID,
    SYMBOL_LIT_INT,
    SYMBOL_LIT_REAL,
    SYMBOL_LIT_CHAR,
    SYMBOL_LIT_STRING,
    SYMBOL_IDENTIFIER,
    SYMBOL_VARIABLE,
    SYMBOL_VECTOR,
    SYMBOL_FUNCTION
};

struct SYMBOL
{
    int type;
    std::string text;
    public:
        SYMBOL(int t, string s): type(t), text(s) {};
};

// Função para incluir um símbolo na estrutura de dados
SYMBOL *symbolInsert(int type, const char *text);

// Função para imprimir a tabela de símbolos
void symbolPrintTable(void);

// Função para inicializar a tabela de símbolos
void initMe(void);
// END OF FILE
#endif