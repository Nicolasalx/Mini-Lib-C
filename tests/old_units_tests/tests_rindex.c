/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** tests_rindex
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern char *rindex(const char *s, int c);

Test(test_rindex, find_last_occurrence)
{
    const char *str = "Hello, world!";
    char *result = rindex(str, 'o');

    cr_assert_str_eq(result, "orld!");
}

Test(test_rindex, character_not_found)
{
    const char *str = "Hello, world!";
    char *result = rindex(str, 'z');

    cr_assert_null(result);
}

Test(test_rindex, empty_string)
{
    const char *str = "";
    char *result = rindex(str, 'a');

    cr_assert_null(result);
}

Test(test_rindex, null_character)
{
    const char *str = "Hello, world!";
    char *result = rindex(str, '\0');

    cr_assert_str_eq(result, "");
}
