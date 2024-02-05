/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strrchr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern char *strrchr(const char *s, int c);

// renvoie un pointeur sur la dernière occurrence du caractère c dans la chaîne s.

Test(test_strrchr, empty_string)
{
    const char *str = "";
    int c = 'o';

    char *result = strrchr(str, c);

    cr_assert_null(result, "Expected NULL for empty string");
}

Test(test_strrchr, character_not_found)
{
    const char *str = "Hello, World";
    int c = 'z';

    char *result = strrchr(str, c);

    cr_assert_null(result, "Expected NULL for character not found");
}

Test(test_strrchr, character_found_at_start)
{
    const char *str = "Hello, World";
    int c = 'H';

    char *result = strrchr(str, c);

    cr_assert_not_null(result, "Expected not NULL for character found");
    cr_assert_eq(*result, 'H', "Expected 'H' at the returned position");
}

Test(test_strrchr, character_found_in_middle)
{
    const char *str = "Hello, World";
    int c = 'o';

    char *result = strrchr(str, c);

    cr_assert_not_null(result, "Expected not NULL for character found");
    cr_assert_eq(*result, 'o', "Expected 'o' at the returned position");
}

Test(test_strrchr, character_found_at_end)
{
    const char *str = "Hello, World";
    int c = 'd';

    char *result = strrchr(str, c);

    cr_assert_not_null(result, "Expected not NULL for character found");
    cr_assert_eq(*result, 'd', "Expected 'd' at the returned position");
}
