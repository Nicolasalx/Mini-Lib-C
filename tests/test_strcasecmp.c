/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** test_strcasecmp
*/

#include "my_test.h"

void test_strcasecmp(void *lib_handle, int *index)
{
    int (*strcasecmp)(const char *, const char *);
    strcasecmp = dlsym(lib_handle, "strcasecmp");
    const char *dlsym_error = dlerror();
    const char *function_name = "Strcasecmp";
    if (dlsym_error) {
        fprintf(stderr, "Error getting symbol: %s\n", dlsym_error);
        dlclose(lib_handle);
        return;
    }

    const char *str1 = "";
    const char *str2 = "";
    int result = strcasecmp(str1, str2);
    if (result != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str1a = "abc";
    const char *str2a = "abc";
    int resulta = strcasecmp(str1a, str2a);
    if (resulta != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str1b = "abc111";
    const char *str2b = "ABC222";
    int resultb = strcasecmp(str1b, str2b);

    if (resultb != -1) {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str1c = "AbC111";
    const char *str2c = "aBc555";
    int resultc = strcasecmp(str1c, str2c);
    if (resultc != -4) {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str1d = "abcdef";
    const char *str2d = "ABCDEF";
    int resultd = strcasecmp(str1d, str2d);
    if (resultd != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_5] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_5] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str1e = "a";
    const char *str2e = "Z";
    int resulte = strcasecmp(str1e, str2e);
    if (resulte != -25) {
        printf("Test [%d] : Test of function [%s] -> [test_6] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_6] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str1f = "Z";
    const char *str2f = "A";
    int resultf = strcasecmp(str1f, str2f);
    if (resultf != 25) {
        printf("Test [%d] : Test of function [%s] -> [test_7] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_7] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
}
