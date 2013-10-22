# compiler
CC = gcc
# flags
CFLAGS = -Wall -g
# general dependencies
DEPS = point.h triangle.h
# object files
OBJ = main.o point_func.o triangle_func.o
# main file name
TARGET = main
# out file name
OUT = out
# standard
STD = -std=c99


all : $(TARGET) 

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(STD) -o $(OUT) $(OBJ) -lm

$(OBJ): $(DEPS)

.PHONY : clean
clean:
	rm -rf $(wildcard *.o) $(wildcard *~)
