CFLAGS=-Wall -Wextra -O2 -std=c99 -pipe -pedantic -Wundef -Wshadow -W -Wwrite-strings -Wcast-align -Wstrict-overflow=5 -Wconversion -Wpointer-arith -Wstrict-prototypes -Wformat=2 -Wsign-compare -Wendif-labels -Wredundant-decls -Winit-self
LDFLAGS=
CFILES=$(wildcard *.c)
OBJ_CODE=$(CFILES:.c=.o)
PROGRAM=timeset
PROGRAM_BINDIR=/usr/bin/$(PROGRAM)

all: $(OBJ_CODE)
	$(CC) $(CFLAGS) $^ -o $(PROGRAM) $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

install:
	install -D -s -m 755 -c $(PROGRAM) $(PROGRAM_BINDIR)
	@echo 'To start the program type: timeset'

uninstall:
	rm -f $(PROGRAM_BINDIR)

clean:
	rm -f *.o
	rm -f $(PROGRAM)

.PHONY: all uninstall install clean
