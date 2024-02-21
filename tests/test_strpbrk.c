/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** test_strpbrk
*/

#include "my_test.h"

void test_strpbrk(void *lib_handle, int *index)
{
    char *(*strpbrk)(const char *, const char *);
    strpbrk = dlsym(lib_handle, "strpbrk");
    const char *dlsym_error = dlerror();
    const char *function_name = "Strpbrk";
    if (dlsym_error) {
        fprintf(stderr, "Error getting symbol: %s\n", dlsym_error);
        dlclose(lib_handle);
        return;
    }

    char *string = "admin";
    char *substring = "a";
    char *result = strpbrk(string, substring);
    if (strcmp(result, "admin") != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    char *string1 = "admin";
    char *substring1 = "VDEa";
    char *result1 = strpbrk(string1, substring1);
    if (strcmp(result1, "admin") != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    char *string2 = "admin";
    char *substring2 = "d";
    char *result2 = strpbrk(string2, substring2);
    if (strcmp(result2, "dmin") != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    char *string3 = "admin";
    char *substring3 = "m";
    char *result3 = strpbrk(string3, substring3);
    if (strcmp(result3, "min") != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    char *string6 = "admin";
    char *substring6 = "n";
    char *result6 = strpbrk(string6, substring6);
    if (strcmp(result6, "n") != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_5] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_5] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
}