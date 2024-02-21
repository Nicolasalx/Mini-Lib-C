/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** test_strlen
*/

#include "my_test.h"

void test_strlen(void *lib_handle, int *index)
{
    size_t (*strlen)(const char *);
    strlen = dlsym(lib_handle, "strlen");
    const char *dlsym_error = dlerror();
    const char *function_name = "Strlen";
    if (dlsym_error) {
        fprintf(stderr, "Error getting symbol: %s\n", dlsym_error);
        dlclose(lib_handle);
        return;
    }

    char *str = "Hello, World";
    size_t lenStr = strlen(str);
    if (lenStr != 12) {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    char *str2 = "Hello, World";
    size_t lenStr2 = strlen(str2);
    if (lenStr2 == 0) {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    char *str3 = "";
    size_t lenStr3 = strlen(str3);
    if (lenStr3 != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
}
