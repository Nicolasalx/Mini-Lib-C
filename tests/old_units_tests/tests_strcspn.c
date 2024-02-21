/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** tests_strcspn
*/

#include <criterion/criterion.h>
#include <string.h>

extern size_t strcspn(const char *s, const char *reject);

Test(test_strcspn, test)
{
    char *str = "Hello, world!";
    const char *delim = "a";

    size_t result = strcspn(str, delim);

    cr_assert_eq(result, strlen(str));
}

Test(test_strcspn2, test)
{
    char *str = "Hello, world!";
    const char *delim = "e";

    size_t result = strcspn(str, delim);

    cr_assert_eq(result, 1);
}

Test(test_strcspn3, test)
{
    char *str = "Hello, world!";
    const char *delim = "H";

    size_t result = strcspn(str, delim);

    cr_assert_eq(result, 0);
}

Test(test_strcspn4, test)
{
    char *str = "Hello, world!";
    const char *delim = "";

    size_t result = strcspn(str, delim);

    cr_assert_eq(result, strlen(str));
}

Test(test_strcspn5, test)
{
    char *str = "Hello, world!";
    const char *delim = "!";

    size_t result = strcspn(str, delim);

    cr_assert_eq(result, 12);
}
