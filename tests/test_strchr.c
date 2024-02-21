/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** test_strchr
*/

#include "my_test.h"

void test_strchr(void *lib_handle, int *index)
{
    char *(*strchr)(const char *, int);
    strchr = dlsym(lib_handle, "strchr");
    const char *dlsym_error = dlerror();
    const char *function_name = "Strchr";
    if (dlsym_error) {
        fprintf(stderr, "Error getting symbol: %s\n", dlsym_error);
        dlclose(lib_handle);
        return;
    }

    const char *str = "";
    int c = 'o';
    char *result = strchr(str, c);
    if (result != NULL) {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    char *str1 = "";
    if (strchr(str1, '\0') != strchr(str1, '\0')) {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str2 = "Hello, World";
    int c2 = 'z';

    char *result2 = strchr(str2, c2);

    if (result2 != NULL) {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    char *str3 = "Hello, World!";
    if (strchr(str3, '\0') != strchr(str3, '\0')) {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str4 = "Hello, World";
    int c4 = 'H';
    char *result4 = strchr(str4, c4);
    if (result4 == NULL) {
        printf("Test [%d] : Test of function [%s] -> [test_5] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_5] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
    if (*result4 != 'H') {
        printf("Test [%d] : Test of function [%s] -> [test_6] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_6] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    char *str5 = "Test Crash";
    if (strchr(str5, 2147489999) != strchr(str5, 2147489999)) {
        printf("Test [%d] : Test of function [%s] -> [test_7] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_7] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
}
