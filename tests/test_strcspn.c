/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** test_strcspn
*/

#include "my_test.h"

void test_strcspn(void *lib_handle, int *index)
{
    size_t (*strcspn)(const char *, const char *);
    strcspn = dlsym(lib_handle, "strcspn");
    const char *dlsym_error = dlerror();
    const char *function_name = "Strcspn";
    if (dlsym_error) {
        fprintf(stderr, "Error getting symbol: %s\n", dlsym_error);
        dlclose(lib_handle);
        return;
    }

    char *str = "Hello, world!";
    const char *delim1 = "a";
    const char *delim2 = "e";
    const char *delim3 = "H";
    const char *delim4 = "";
    const char *delim5 = "!";

    size_t result1 = strcspn(str, delim1);
    size_t result2 = strcspn(str, delim2);
    size_t result3 = strcspn(str, delim3);
    size_t result4 = strcspn(str, delim4);
    size_t result5 = strcspn(str, delim5);

    if (result1 != strlen(str)) {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    if (result2 != 1) {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    if (result3 != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    if (result4 != strlen(str)) {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    if (result5 != 12) {
        printf("Test [%d] : Test of function [%s] -> [test_5] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_5] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
}