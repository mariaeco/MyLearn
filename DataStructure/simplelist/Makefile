 APPS = ./app
 BIN = ./bin
 INCLUDE = ./include
 OBJ = ./obj
 SRC = ./src


all:  libed myapps

libed: $(OBJ)/funcoes.o
#biblioteca de ed: posso fazer assim tbm, sem o %.o la em baixo gcc -c $(SRC)/funcoes.c -I $(INCLUDE)/ -o $(OBJ)/funcoes.o

myapps:#apps
	gcc $(APPS)/main.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/main

#usando assim, so compilo quando houver modificacao
(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

run: #caminho para rodar  	PATH=$(BIN) && main
	$(BIN)/main

clean: #limpa os arquivos de compilação 
	rm -rf *.o
