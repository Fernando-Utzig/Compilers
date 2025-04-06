### Fernando Vieira Utzig - 00324861

CXX = g++
CXXFLAGS = -std=c++11 -Wall

target: etapa2

etapa2: lex.yy.o main.o symbols.o parser.o parser.hpp
	$(CXX) $(CXXFLAGS) lex.yy.o main.o symbols.o parser.o -o etapa2

%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Essa linha foi adicionada para evitar o erro:
# make: *** No rule to make target 'parser.hpp', needed by 'lex.yy.cpp'
parser.hpp: parser.cpp
	touch parser.hpp 

lex.yy.cpp: scanner.l parser.hpp
	flex -o lex.yy.cpp scanner.l 

parser.cpp: parser.ypp
	bison -o parser.cpp -d parser.ypp

parser.o: parser.cpp parser.hpp
	$(CXX) $(CXXFLAGS) -c parser.cpp -o parser.o

clean:
	rm -f etapa2 lex.yy.cpp *.o parser.cpp parser.hpp