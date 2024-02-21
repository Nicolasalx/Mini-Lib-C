/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** test_strcmp
*/

#include "my_test.h"

void test_strcmp(void *lib_handle, int *index)
{
    int (*strcmp)(const char *, const char *);
    strcmp = dlsym(lib_handle, "strcmp");
    const char *dlsym_error = dlerror();
    const char *function_name = "Strcmp";
    if (dlsym_error) {
        fprintf(stderr, "Error getting symbol: %s\n", dlsym_error);
        dlclose(lib_handle);
        return;
    }

    const char *str1 = "";
    const char *str2 = "";
    int result = strcmp(str1, str2);
    if (result != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str1a = "hello";
    const char *str2a = "hell";
    int resulta = strcmp(str1a, str2a);
    if (resulta != 111) {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str1b = "hello";
    const char *str2b = "hello";
    int resultb = strcmp(str1b, str2b);
    if (resultb != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str1c = "hell";
    const char *str2c = "hello";
    int resultc = strcmp(str1c, str2c);
    if (resultc != -111) {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *str1d = "hello";
    const char *str2d = "hellx";
    int resultd = strcmp(str1d, str2d);
    if (resultd != -9) {
        printf("Test [%d] : Test of function [%s] -> [test_5] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_5] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
}
