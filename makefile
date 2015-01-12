# Makefile for C-BST
SHELL=/bin/bash

# Set compilation options:
#
# -O0 no optimizations; remove after debugging
# -m32 create 32-bit executable
# -std=c99 use C99 Standard features
# -Wall show "all" warnings
# -W show even more warnings (annoying)
# -ggdb3 add extra debug info; remove after debugging

CC=gcc
CFLAGS= -m64 -std=c99 -Wall -O0 -ggdb3
OBJECTS = driver.o BST.o StringDT.o

# Build the test code (full project):
driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o driver.exe $(OBJECTS)

# Rules for components:
driver.o: BST.c BST.h StringDT.c StringDT.h
	$(CC) $(CFLAGS) -c driver.c

# Cleaning rules:
clean:
	rm -f *.o *.stackdump
