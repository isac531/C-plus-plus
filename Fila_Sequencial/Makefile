# Nome do compilador C++
CXX = g++

# Flags de compilação (Wall: mostra todos os warnings, g: debug, std=c++11: padrão do C++)
CXXFLAGS = -Wall -g -std=c++11

# Nome do executável final
TARGET = programa_fila_cpp

# Arquivos objeto (.o) necessários
OBJS = main.o fila.o

# Regra principal: o que fazer quando 'make' é executado sem argumentos
all: $(TARGET)

# Regra para criar o executável final a partir dos arquivos objeto
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regra para compilar main.cpp em main.o
main.o: main.cpp fila.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Regra para compilar fila.cpp em fila.o
fila.o: fila.cpp fila.hpp
	$(CXX) $(CXXFLAGS) -c fila.cpp

# Regra para limpar os arquivos gerados (executável e objetos)
clean:
	rm -f $(TARGET) $(OBJS)

# Regra para compilar e executar o programa de uma vez
run: all
	./$(TARGET)