#include <check.h>
#include <stdlib.h>
#include "../bit_vector.h"

START_TEST (test_sample_1)
{
    fail_unless(1 == 2, "One is not equal to 2"); 
}
END_TEST

START_TEST (test_sample_2)
{
    fail_unless(1 == 1, "One is not equal to 1");
}
END_TEST

Suite *bit_vector_suite(void)
{
    Suite *s = suite_create("Bit Vector");

    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_sample_1);
    tcase_add_test(tc_core, test_sample_2);
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

