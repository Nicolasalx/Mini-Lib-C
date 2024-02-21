/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** my_test
*/

#ifndef MY_TEST_H_
    #define MY_TEST_H_

    #define RED "\x1b[31m"
    #define GREEN "\x1b[32m"
    #define RESET "\x1b[0m"

    #define SUCCEED "[SUCCEED]"
    #define FAILED "[FAILED]"

    #include <stdio.h>
    #include <dlfcn.h>
    #include <string.h>
    #include <stdbool.h>

    void test_strrchr(void *lib_handle, int *index);
    void test_strstr(void *lib_handle, int *index);
    void test_strpbrk(void *lib_handle, int *index);
    void test_strncmp(void *lib_handle, int *index);
    void test_strlen(void *lib_handle, int *index);
    void test_strcmp(void *lib_handle, int *index);
    void test_strchr(void *lib_handle, int *index);
    void test_strcasecmp(void *lib_handle, int *index);
    void test_memcpy(void *lib_handle, int *index);
    void test_memmove(void *lib_handle, int *index);
    void test_memset(void *lib_handle, int *index);
    void test_strcspn(void *lib_handle, int *index);

#endif /* !MY_TEST_H_ */
