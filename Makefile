# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test

CC = g++
CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -I$(INC_DIR)
RM = rm -rf

.PHONY: all clean distclean doxy

all: dir petfera

# Cria os diretórios necessários
dir:
	mkdir -p bin build

# Opção para depurar
debug: CPPFLAGS += -pg -g -O0
debug: petfera

linux: petfera.so petfera_dinamica

####	biblioteca dinâmica petfera para linux	####
$(LIB_DIR)/petfera.so: $(INC_DIR)/animal.h $(INC_DIR)/funcionario.h $(INC_DIR)/petfera.h $(INC_DIR)/anfibio.h $(INC_DIR)/ave.h $(INC_DIR)/reptil.h $(INC_DIR)/mamifero.h $(INC_DIR)/aveExotica.h $(INC_DIR)/AveNativa.h $(INC_DIR)/animalSilvestre.h $(INC_DIR)/animalNativo.h $(INC_DIR)/animalExotico.h $(INC_DIR)/veterinario.h $(INC_DIR)/tratador.h
	$(CC) -shared -fPIC -o $A $^ 
	@echo "+++ [Biblioteca dinamica criada em $@] +++"

####	Pet Fera		####
petfera: $(OBJ_DIR)/main.o $(OBJ_DIR)/petfera.o $(OBJ_DIR)/animal.o $(OBJ_DIR)/anfibio.o $(OBJ_DIR)/ave.o $(OBJ_DIR)/reptil.o $(OBJ_DIR)/mamifero.o $(OBJ_DIR)/aveExotica.o $(OBJ_DIR)/aveNativa.o $(OBJ_DIR)/animalSilvestre.o $(OBJ_DIR)/animalNativo.o $(OBJ_DIR)/animalExotico.o $(OBJ_DIR)/veterinario.o $(OBJ_DIR)/tratador.o $(OBJ_DIR)/funcionario.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel questao01 criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/petfera.o: $(SRC_DIR)/petfera.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/animal.o: $(SRC_DIR)/animal.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/anfibio.o: $(SRC_DIR)/anfibio.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/ave.o: $(SRC_DIR)/ave.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/reptil.o: $(SRC_DIR)/reptil.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/mamifero.o: $(SRC_DIR)/mamifero.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/aveExotica.o: $(SRC_DIR)/aveExotica.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/aveNativa.o: $(SRC_DIR)/aveNativa.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/animalSilvestre.o: $(SRC_DIR)/animalSilvestre.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/animalNativo.o: $(SRC_DIR)/animalNativo.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/animalExotico.o: $(SRC_DIR)/animalExotico.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/veterinario.o: $(SRC_DIR)/veterinario.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/tratador.o: $(SRC_DIR)/tratador.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/funcionario.o: $(SRC_DIR)/funcionario.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

# Copiando o .so para as três possiveis localizações padrões para shared libraries
install: $(LIB_DIR)/libPetFera.so
	sudo cp $(LIB_DIR)/libPetFera.so /lib/
	sudo cp $(LIB_DIR)/libPetFera.so /usr/lib/
	sudo cp $(LIB_DIR)/libPetFera.so /usr/local/lib/

# Removendo o .so das três possiveis localizações padrões para shared libraries
uninstall: $(LIB_DIR)/libPetFera.so	
	sudo rm -f /lib/libPetFera.so
	sudo rm -f /usr/lib/libPetFera.so
	sudo rm -f /usr/local/lib/libPetFera.so

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Limpar os arquivos objetos e executáveis
clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	$(RM) $(DOC_DIR)/*
