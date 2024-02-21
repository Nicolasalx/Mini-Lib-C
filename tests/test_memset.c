/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** test_memset
*/

#include "my_test.h"

void test_memset(void *lib_handle, int *index)
{
    void *(*memset)(void *, int, size_t);
    memset = dlsym(lib_handle, "memset");
    const char *dlsym_error = dlerror();
    const char *function_name = "Memset";
    if (dlsym_error) {
        fprintf(stderr, "Error getting symbol: %s\n", dlsym_error);
        dlclose(lib_handle);
        return;
    }

    char buffer[10];
    bool has_failed = false;
    memset(buffer, 0, sizeof(buffer));
    for (size_t i = 0; i < sizeof(buffer); ++i) {
        if (buffer[i] != 0) {
            has_failed = true;
            break;
        }
    }
    if (has_failed == true) {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    bool has_failed2 = false;
    char buffer2[10];
    memset(buffer2, 'A', sizeof(buffer2));
    for (size_t i = 0; i < sizeof(buffer); ++i) {
        if (buffer2[i] != 'A') {
            has_failed2 = true;
            break;
        }
    }
    if (has_failed2 == true) {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    struct {
        char x;
        int y;
    } dataX;
    memset(&dataX, 0, sizeof(dataX));

    if (dataX.x != '\0') {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
    if (dataX.y != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
}
