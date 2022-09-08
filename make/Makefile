#makefile to compile all the files
INC = /home/richa/Demosock/inc
BIN = /home/richa/Demosock/bin
SRC =/home/richa/Demosock/src
OBJ = /home/richa/Demosock/obj
DATA = /home/richa/Demosock/data

LFLAGS = -o
GCC = gcc -fprofile-arcs -ftest-coverage
CFLAGS =  -c -g
IFLAGS = -I $(INC)

all: $(BIN)/client $(BIN)/fork

$(OBJ)/forkclient.o : $(SRC)/forkclient.c
	$(GCC) $(CFLAGS) $(SRC)/forkclient.c $(IFLAGS) 
	mv *.o /home/richa/Demosock/obj

$(OBJ)/login.o : $(SRC)/login.c
	$(GCC) $(CFLAGS) $(SRC)/login.c $(IFLAGS) 
	mv *.o /home/richa/Demosock/obj

$(BIN)/client : $(OBJ)/forkclient.o $(OBJ)/login.o 
	$(GCC) $(OBJ)/forkclient.o $(OBJ)/login.o $(LFLAGS) $(BIN)/client

$(OBJ)/forkserver.o : $(SRC)/forkserver.c 
	$(GCC) $(CFLAGS) $(SRC)/forkserver.c $(IFLAGS)
	mv *.o /home/richa/Demosock/obj

$(BIN)/fork : $(OBJ)/forkserver.o 
	$(GCC) $(OBJ)/forkserver.o $(LFLAGS) $(BIN)/fork
