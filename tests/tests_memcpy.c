/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** tests_memcpy
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern void *memcpy(void *dest, const void *src, size_t n);

Test(test_memcpy, copy_string)
{
    const char *src = "Hello, world!";
    char dest[20];

    memcpy(dest, src, strlen(src) + 1);

    cr_assert_str_eq(dest, src);
}

Test(test_memcpy, copy_array)
{
    int src[] = {1, 2, 3, 4, 5};
    int dest[5];

    memcpy(dest, src, sizeof(src));

    for (int i = 0; i < 5; ++i) {
        cr_assert(dest[i] == src[i]);
    }
}

Test(test_memcpy, copy_struct)
{
    struct {
        int x;
        float y;
    } src = {10, 3.14}, dest;

    memcpy(&dest, &src, sizeof(src));

    cr_assert(memcmp(&dest, &src, sizeof(src)) == 0);
}

Test(test_memcpy, overlapping_buffers)
{
    char buffer[] = "Hello, world!";
    char *src = buffer;
    char dest[20];

    memcpy(dest, src, strlen(src) + 1);

    cr_assert_str_eq(dest, src);
}
