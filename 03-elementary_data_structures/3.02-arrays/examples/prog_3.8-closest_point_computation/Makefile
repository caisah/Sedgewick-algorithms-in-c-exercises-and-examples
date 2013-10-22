# compiler
CC = gcc
# flags
CFLAGS = -Wall -g
# general dependencies
DEPS = Point.h
# object files
OBJ = prog_3.8-closest_point_computetion.o \
      point_dt_implementation.o
# main file name
TARGET = prog_3.8-closest_point_computetion
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
	rm -rf $(wildcard *.o) $(wildcard *~)
