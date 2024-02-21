/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** test_memmove
*/

#include "my_test.h"

void test_memmove(void *lib_handle, int *index)
{
    void *(*memmove)(void *, const void *, size_t);
    memmove = dlsym(lib_handle, "memmove");
    const char *dlsym_error = dlerror();
    const char *function_name = "Memmove";
    if (dlsym_error) {
        fprintf(stderr, "Error getting symbol: %s\n", dlsym_error);
        dlclose(lib_handle);
        return;
    }

    char *dest1 = strdup("dest");
    char *dest2 = strdup("dest");

    char *src1 = strdup("Hello, src");
    char *src2 = strdup("Hello, src");

    char *result = memmove(dest1, src1, 4);
    char *result2 = memmove(dest2, src2, 4);

    if (strcmp(result, result2) != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
    if (strcmp(dest1, dest2) != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    char *src1a = strdup("Hello, src");
    char *src2a = strdup("Hello, src");

    char *dest1a = strdup("dest");
    char *dest2a = strdup("dest");

    char *resulta = memmove(dest1a, src1a, 4);
    char *result2a = memmove(dest2a, src2a, 4);

    if (strcmp(resulta, result2a) != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
    if (strcmp(dest1a, dest2a) != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
}