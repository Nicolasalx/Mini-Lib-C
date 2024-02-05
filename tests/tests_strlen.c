/*
** EPITECH PROJECT, 2024
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

// renvoie la taille de la string

extern size_t strlen(const char *__s);

Test (test_strlen, test)
{
    char *str = "Hello, World";
    size_t lenStr = strlen(str);

    cr_assert(lenStr == 12);
}

Test (test_strlen2, test)
{
    char *str = "Hello, World";
    size_t lenStr = strlen(str);

    cr_assert_neq(lenStr, 0);
}

Test (test_strlen3, test)
{
    char *str = "";
    size_t lenStr = strlen(str);

    cr_assert_eq(lenStr, 0);
}

