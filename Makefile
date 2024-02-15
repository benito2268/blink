# main Makefile for the "blink" project
# author: Ben Staehle
# date:   12/17/23
BIN = bin
LIB = lib

TARGET = $(BIN)/blink

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
OBJS := $(OBJS:%=$(BIN)/%)

CC = gcc
CFLAGS = -Wall -Wextra -g -std=gnu99 -m64
LDFLAGS =

all: $(TARGET)
.PHONY: clean

$(BIN)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS) $(SRCS)
	$(CC) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)
	rm -f $(OBJS)