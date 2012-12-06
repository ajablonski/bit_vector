#ifndef BIT_VECTOR_H
#define BIT_VECTOR_H

#define BITS_PER_BYTE 8

void *create_bit_vector(size_t bits);

void free_bit_vector(void *bv);

void set_bit(void *bv, size_t bit);
void clear_bit(void *bv, size_t bit);
void set_bit(void *bv, size_t bit);
void clear_bit(void *bv, size_t bit);
void set_bit_vector(void *bv);
void clear_bit_vector(void *bv);
unsigned int get_bit(void *bv, size_t bit);


#endif /* BIT_VECTOR_H */

