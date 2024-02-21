/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** test_strrchr
*/

#include "my_test.h"

void test_strrchr(void *lib_handle, int *index)
{
    char *(*strrchr)(const char *, int);
    strrchr = dlsym(lib_handle, "strrchr");
    const char *dlsym_error = dlerror();
    const char *function_name = "Strrchr";
    if (dlsym_error) {
        fprintf(stderr, "Error getting symbol: %s\n", dlsym_error);
        dlclose(lib_handle);
        return;
    }

    const char *str = "";
    int c = 'o';
    char *result = strrchr(str, c);
    if (result != NULL) {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str1 = "Hello, World";
    int c1 = 'z';
    char *result1 = strrchr(str1, c1);

    if (result1 != NULL) {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str2 = "Hello, World";
    int c2 = 'H';
    char *result2 = strrchr(str2, c2);
    if (result2 == NULL) {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    if (*result2 != 'H') {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
}