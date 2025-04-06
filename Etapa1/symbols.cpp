// Fernando Vieira Utzig - 00324861
//
#include "symbols.hpp"
#include "tokens.h"
#include <string>
#include <map>

// create map
std::map<std::string, SYMBOL*> SymbolTable;

const char* SymbolName[] = {
    "SYMBOL_INVALID", "SYMBOL_ZEROS", "SYMBOL_ID", "SYMBOL_LIT_INT", "SYMBOL_LIT_REAL", "SYMBOL_LIT_CHAR", "SYMBOL_LIT_STRING", "SYMBOL_IDENTIFIER"
};

// Função para incluir um símbolo na estrutura de dados
SYMBOL *symbolInsert(int type, const char *text) {
    std::string key(text);
    if (SymbolTable.find(key) != SymbolTable.end()) {
        return SymbolTable.find(key)->second;
    }

    SymbolType enumType;
    switch (type) {
        case LIT_INT:       enumType = SYMBOL_LIT_INT; break;
        case LIT_REAL:      enumType = SYMBOL_LIT_REAL; break;
        case LIT_CHAR:      enumType = SYMBOL_LIT_CHAR; break;
        case LIT_STRING:    enumType = SYMBOL_LIT_STRING; break;
        case TK_IDENTIFIER: enumType = SYMBOL_IDENTIFIER; break;
        default:            enumType = SYMBOL_INVALID; break;
    }

    SYMBOL *newsymbol = new SYMBOL(enumType, key);
    SymbolTable[key] = newsymbol;
    return newsymbol;
}

// Função para imprimir a tabela de símbolos
void symbolPrintTable(void) {
    printf("\n--- Symbol Table ---\n");
    for (const auto& entry : SymbolTable) {
        printf("Symbol[%s,%s]\n", SymbolName[entry.second->type], entry.second->text.c_str());
    }
    printf("--- End of Symbol Table ---\n");
}

void initMe(void) {
    SymbolTable.clear(); // Limpa a tabela de símbolos
}