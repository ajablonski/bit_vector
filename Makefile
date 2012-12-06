CC=gcc
CFLAGS=-c -Wall
POSTFLAGS=-lcheck_pic
LDFLAGS=
SOURCES=bit_vector.c test/check_bit_vector.c
OBJECTS=$(SOURCES:.c=.o)

all: $(SOURCES) bit_vector

bit_vector: $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(POSTFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

test: all 
	./test/check_bit_vector
    

clean: 
	rm -f $(OBJECTS) $(OBJECTS:.o=)


