/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** test_memcpy
*/

#include "my_test.h"

void test_memcpy(void *lib_handle, int *index)
{
    void *(*memcpy)(void *, const void *, size_t);
    memcpy = dlsym(lib_handle, "memcpy");
    const char *dlsym_error = dlerror();
    const char *function_name = "Memcpy";
    if (dlsym_error) {
        fprintf(stderr, "Error getting symbol: %s\n", dlsym_error);
        dlclose(lib_handle);
        return;
    }

    const char *src = "Hello, world!";
    char dest[20];

    memcpy(dest, src, strlen(src) + 1);

    if (strcmp(dest, src) != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    int src2[] = {1, 2, 3, 4, 5};
    int dest2[5];

    bool has_failed = false;
    memcpy(dest2, src2, sizeof(src2));
    for (int i = 0; i < 5; ++i) {
        if (dest2[i] != src2[i]) {
            printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, RED FAILED RESET);
            has_failed = true;
            break;
        }
    }
    if (has_failed == false) {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
}