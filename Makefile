#### File           : Makefile
#### Description    : Make file for project2 
#### Author         : ***Cesar Colato***
#### Date           : ***3/31/2023***
#### Notes          : ***N/A

# Makefile for CMSC257 Project2
#
# Make environment
CC = gcc
CFLAGS= -c -g -Wall $(INCLUDES)

# Files
OBJECT_FILES = p2.o p2-support.o

# Productions
all : p2

p2 : $(OBJECT_FILES)
	$(CC) $^ -o $@

p2.o : cmsc257-p2.c p2-support.h
	$(CC) $(CFLAGS) $< -o $@ 

p2-support.o : p2-support.c p2-support.h
	$(CC) $(CFLAGS) $< -o $@ 

clean : 
	rm -v p2 $(OBJECT_FILES)              
