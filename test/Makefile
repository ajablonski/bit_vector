CC=gcc
CFLAGS=-c -Wall 
POSTFLAGS=-lcheck_pic
LDFLAGS=
SOURCES=check_bit_vector.c
OBJECTS=$(SOURCES:.c=.o)

all: $(SOURCES) check_bit_vector

check_bit_vector: $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(POSTFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ 

clean: 
	rm -f $(OBJECTS) $(OBJECTS:.o=)
