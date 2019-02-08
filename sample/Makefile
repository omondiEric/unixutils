EXECS    = my-stat  # A list of all executable files
CC       = gcc    # Command to invode the C compiler

CFLAGS   = -Wall -Wextra -Wpedantic -Wstrict-aliasing
LDFLAGS  = 

SRC      = $(wildcard *.c)
OBJ      = $(SRC:.c=.o)

all: $(EXECS)

my-stat: my-stat.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXECS)
