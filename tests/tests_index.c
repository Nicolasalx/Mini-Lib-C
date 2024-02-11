/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** tests_index
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern char *index(const char *s, int c);

Test(test_index, find_character_in_string)
{
    const char *str = "Hello, world!";
    char *result = index(str, 'o');

    cr_assert_str_eq(result, "o, world!");
}

Test(test_index, character_not_found)
{
    const char *str = "Hello, world!";
    char *result = index(str, 'z');

    cr_assert_null(result);
}

Test(test_index, empty_string)
{
    const char *str = "";
    char *result = index(str, 'a');

    cr_assert_null(result);
}

Test(test_index, null_character)
{
    const char *str = "Hello, world!";
    char *result = index(str, '\0');

    cr_assert_str_eq(result, "");
}