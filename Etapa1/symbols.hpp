// Fernando Vieira Utzig - 00324861
//
// symbols.hpp - tabela de símbolos

// Container com nodos dentro
// nodos vao armazenar os simbolos que o usuario criou

#include <string>

using namespace std;

enum SymbolType {
    SYMBOL_INVALID, SYMBOL_ZEROS, SYMBOL_ID, SYMBOL_LIT_INT, SYMBOL_LIT_REAL, SYMBOL_LIT_CHAR, SYMBOL_LIT_STRING, SYMBOL_IDENTIFIER
};

struct SYMBOL
{
    int type;
    string text;
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