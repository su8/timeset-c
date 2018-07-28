CC=gcc
CFLAGS=-Wall -Wextra -O2 -std=c99 -pipe -pedantic -Wundef -Wshadow -W -Wwrite-strings -Wcast-align -Wstrict-overflow=5 -Wconversion -Wpointer-arith -Wstrict-prototypes -Wformat=2 -Wsign-compare -Wendif-labels -Wredundant-decls -Winit-self
LDFLAGS=
BINDIR=/usr/bin
CFILES=$(wildcard *.c)
OBJ_CODE=$(CFILES:.c=.o)
INZTALL=/usr/bin/install -Dm -c

.PHONY: all uninstall install

all: $(OBJ_CODE)
	$(CC) $(CFLAGS) $^ -o ./timeset $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

install: all
	$(INZTALL) timeset $(BINDIR)/timeset
	@echo 'To start the program type: timeset'

uninstall:
	rm $(BINDIR)/timeset
