CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=bit_vector.c
OBJECTS=$(SOURCES:.c=.o)

all: $(SOURCES) bit_vector

bit_vector: $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -f $(OBJECTS) $(OBJECTS:.o=)
