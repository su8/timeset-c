#   07/29/2018
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or
#   (at your option) any later version.

#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.

#   You should have received a copy of the GNU General Public License
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#   MA 02110-1301, USA.

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
