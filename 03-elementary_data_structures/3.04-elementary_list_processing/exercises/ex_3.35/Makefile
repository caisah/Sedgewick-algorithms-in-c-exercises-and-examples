# compiler
CC = gcc
# flags
CFLAGS = -Wall -g
# general dependencies
DEPS = list.h
# object files
OBJ = main.o list_functions.o
# main file name
TARGET = main
# out file name
OUT = out
# standard
STD = -std=c99


all : $(TARGET) 

$(TARGET): $(OBJ)
	gcc $(CFLAGS) $(STD) -o $(OUT) $(OBJ) -lm

$(OBJ): $(DEPS)

.PHONY : clean
clean:
	rm -rf $(wildcard *.o) $(wildcard *~) $(OUT)
