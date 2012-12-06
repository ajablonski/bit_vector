#include <check.h>
#include <stdlib.h>
#include "../bit_vector.h"

START_TEST (test_create_bit_vector)
{
    size_t bytes = 3;
    size_t bits = bytes * BITS_PER_BYTE;
    unsigned int i;
    char *bv = create_bit_vector(bits);
    fail_if(bv == NULL,
        "Create_bit_vector returned NULL pointer");
    for (i = 0; i < bytes; i ++){
        if (bv[i] != 0) {
            fail("Byte %d not initialized properly", i); 
        }
    }
    free_bit_vector(bv);
}
END_TEST

START_TEST (test_set_vector)
{
    size_t bytes = 3;
    size_t bits = bytes * BITS_PER_BYTE;
    unsigned int i;
    char *bv = create_bit_vector(bits);
    set_bit_vector(bv);
    fail_if(bv == NULL,
        "Create_bit_vector returned NULL pointer");
    for (i = 0; i < bytes; i ++) {
        if (bv[i] != 0xff) {
            fail("Byte %d not set", i); 
        }
    }
    free_bit_vector(bv);
}
END_TEST

START_TEST (test_clear_vector)
{

    size_t bytes = 3;
    size_t bits = bytes * BITS_PER_BYTE;
    unsigned int i;
    char *bv = create_bit_vector(bits);
    set_bit_vector(bv);
    clear_bit_vector(bv);
    fail_if(bv == NULL,
        "Create_bit_vector returned NULL pointer");
    for (i = 0; i < bytes; i ++) {
        if (bv[i] != 0) {
            fail("Byte %d not cleared", i); 
        }
    }
    free_bit_vector(bv);
}
END_TEST

START_TEST (test_set_bit)
{
    size_t bytes = 3;
    size_t bits = bytes * BITS_PER_BYTE;
    unsigned int i;
    char *bv = create_bit_vector(bits);
    
    set_bit(bv, 0);
    fail_unless(bv[0] == 0x1);
    free_bit_vector(bv);
}
END_TEST

START_TEST (test_clear_bit)
{
    size_t bytes = 3;
    size_t bits = bytes * BITS_PER_BYTE;
    unsigned int i;
    char *bv = create_bit_vector(bits);
    
    clear_bit(bv, 0);
    fail_unless(bv[0] == 0x0);
    free_bit_vector(bv);
}
END_TEST

START_TEST (test_get_bit)
{
    size_t bits = 20;
    char *bv = create_bit_vector(bits);

    set_bit(bv, 2);

    fail_unless(get_bit(bv, 2) == 1,
        "Bit not returned properly");

    free_bit_vector(bv);
}
END_TEST

Suite *bit_vector_suite(void)
{
    Suite *s = suite_create("Bit Vector");

    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_create_bit_vector);
    tcase_add_test(tc_core, test_set_vector);
    tcase_add_test(tc_core, test_clear_vector);
    tcase_add_test(tc_core, test_set_bit);
    tcase_add_test(tc_core, test_clear_bit);
    tcase_add_test(tc_core, test_get_bit);
    suite_add_tcase(s, tc_core);

    return s;
}

int main()
{
    int failed = 0;

    Suite *s = bit_vector_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (failed == 0) ? EXIT_SUCCESS: EXIT_FAILURE;
}

