#include <stdlib.h>
#include "bit_vector.h"

void *create_bit_vector(size_t bits) 
{
    size_t bytes = (bits + BITS_PER_BYTE - 1) / BITS_PER_BYTE; // Ceiling
    
    char *bv = malloc(bytes);

    unsigned int i;
    for (i = 0; i < bytes; i++) {
        bv[i] = 0;
    }
    
    return bv;
}


void set_bit(void *bv, size_t bit)
{
}

void clear_bit(void *bv, size_t bit)
{
}

void set_bit_vector(void *bv)
{
}

void clear_bit_vector(void *bv)
{
}

unsigned int get_bit(void *bv, size_t bit)
{
    return 0;
}

void free_bit_vector(void *bv)
{
    free(bv); 
}

