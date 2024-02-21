/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** test_main
*/

#include "my_test.h"

int main()
{
    void *lib_handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!lib_handle) {
        fprintf(stderr, "Error loading library: %s\n", dlerror());
        return 1;
    }

    int indexTest = 0;
    int nbTestTotal = 52;

    test_strcspn(lib_handle, &indexTest);
    test_memcpy(lib_handle, &indexTest);
    test_memmove(lib_handle, &indexTest);
    test_memset(lib_handle, &indexTest);
    test_strcasecmp(lib_handle, &indexTest);
    test_strchr(lib_handle, &indexTest);
    test_strcmp(lib_handle, &indexTest);
    test_strlen(lib_handle, &indexTest);
    test_strncmp(lib_handle, &indexTest);
    test_strpbrk(lib_handle, &indexTest);
    test_strstr(lib_handle, &indexTest);

    printf("\n%d tests have " GREEN SUCCEED RESET "\n", indexTest);
    printf("%d tests have " RED FAILED RESET "\n", nbTestTotal - indexTest);

    dlclose(lib_handle);

    return 0;
}
