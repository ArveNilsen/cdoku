CC = clang
CFLAGS = -Wall -Werror -Wextra -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: cdoku run clean

cdoku:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./cdoku

clean:
	rm cdoku