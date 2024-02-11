/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** tests_memset
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>

extern void *memset(void *s, int c, size_t n);

Test(test_memset, set_to_zero)
{
    char buffer[10];
    memset(buffer, 0, sizeof(buffer));

    for (size_t i = 0; i < sizeof(buffer); ++i) {
        cr_assert(buffer[i] == 0);
    }
}

Test(test_memset, set_to_value)
{
    char buffer[10];
    memset(buffer, 'A', sizeof(buffer));

    for (size_t i = 0; i < sizeof(buffer); ++i) {
        cr_assert(buffer[i] == 'A');
    }
}

Test(test_memset, set_partial)
{
    char buffer[10];
    memset(buffer, 'A', 5);

    for (size_t i = 0; i < 5; ++i) {
        cr_assert(buffer[i] == 'A');
    }

    for (size_t i = 5; i < sizeof(buffer); ++i) {
        cr_assert(buffer[i] != 'A');
    }
}

Test(test_memset, set_struct)
{
    struct {
        int x;
        float y;
    } data;

    memset(&data, 0, sizeof(data));

    cr_assert(data.x == 0);
    cr_assert(data.y == 0.0f);
}