CC=gcc
CFLAGS=-c -Wall
POSTFLAGS=-lcheck_pic
LDFLAGS=
SOURCES=bit_vector.c test/check_bit_vector.c
OBJECTS=$(SOURCES:.c=.o)

all: $(SOURCES) test

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

test:  
	$(CC) $(LDFLAGS) $(OBJECTS) -o check_bit_vector $(POSTFLAGS)
	./check_bit_vector

clean: 
	rm -f $(OBJECTS) $(OBJECTS:.o=)

.PHONY: test
