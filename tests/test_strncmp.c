/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** test_strncmp
*/

#include "my_test.h"

void test_strncmp(void *lib_handle, int *index)
{
    int (*strncmp)(const char *, const char *, size_t);
    strncmp = dlsym(lib_handle, "strncmp");
    const char *dlsym_error = dlerror();
    const char *function_name = "Strncmp";
    if (dlsym_error) {
        fprintf(stderr, "Error getting symbol: %s\n", dlsym_error);
        dlclose(lib_handle);
        return;
    }

    const char *str1 = "";
    const char *str2 = "";
    int result = strncmp(str1, str2, 10);
    if (result != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str1a = "abc";
    const char *str2a = "abc";
    int resulta = strncmp(str1a, str2a, 0);
    if (resulta != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str1b = "abc111";
    const char *str2b = "abc222";
    int resultb = strncmp(str1b, str2b, 3);
    if (resultb != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str1c = "abc111";
    const char *str2c = "abc555";
    int resultc = strncmp(str1c, str2c, 4);
    if (resultc != -4) {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str1d = "abcdef";
    const char *str2d = "abcdef";
    int resultd = strncmp(str1d, str2d, 0);
    if (resultd != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_5] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_5] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
}