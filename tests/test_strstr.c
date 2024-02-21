/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** test_strstr
*/

#include "my_test.h"

void test_strstr(void *lib_handle, int *index)
{
    char *(*strstr)(const char *, const char *);
    strstr = dlsym(lib_handle, "strstr");
    const char *dlsym_error = dlerror();
    const char *function_name = "Strstr";
    if (dlsym_error) {
        fprintf(stderr, "Error getting symbol: %s\n", dlsym_error);
        dlclose(lib_handle);
        return;
    }

    const char *meule_de_foin = "Hello, world!";
    const char *aiguille = "o";
    const char *result = strstr(meule_de_foin, aiguille);
    if (strcmp(result, "o, world!") != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_1] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *meule_de_foin1 = "Hello, world!";
    const char *aiguille1 = "H";
    const char *result1 = strstr(meule_de_foin1, aiguille1);
    if (strcmp(result1, "Hello, world!") != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_2] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    const char *meule_de_foin2 = "Hello, world!";
    const char *aiguille2 = "worl";
    const char *result2 = strstr(meule_de_foin2, aiguille2);
    if (strcmp(result2, "world!") != 0) {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_3] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    char *s1 = strdup("");
    char *s2 = strdup("\0");
    if (strstr(s1, s2) != strstr(s1, s2)) {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_4] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }

    if (strstr(s2, s1) != strstr(s2, s1)) {
        printf("Test [%d] : Test of function [%s] -> [test_5] %s\n", *index, function_name, RED FAILED RESET);
    } else {
        printf("Test [%d] : Test of function [%s] -> [test_5] %s\n", *index, function_name, GREEN SUCCEED RESET);
        ++*index;
    }
}