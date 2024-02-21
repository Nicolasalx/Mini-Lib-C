/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strchr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern char *strchr(const char *s, int c);

// renvoie un pointeur sur la première occurrence du caractère c dans la chaîne s.

Test(test_strchr, empty_string)
{
    const char *str = "";
    int c = 'o';

    char *result = strchr(str, c);

    cr_assert_null(result, "Expected NULL for empty string");
}

Test(test_strchr, TestAllEmpty)
{
    char *str = "";

    cr_assert(strchr(str, '\0') == strchr(str, '\0'));
}

Test(test_strchr, character_not_found)
{
    const char *str = "Hello, World";
    int c = 'z';

    char *result = strchr(str, c);

    cr_assert_null(result, "Expected NULL for character not found");
}

Test(test_strchr, testBackslachZero)
{
    char *str = "Hello, World!";

    cr_assert(strchr(str, '\0') == strchr(str, '\0'));
}

Test(test_strchr, character_found_at_start)
{
    const char *str = "Hello, World";
    int c = 'H';

    char *result = strchr(str, c);

    cr_assert_not_null(result, "Expected not NULL for character found");
    cr_assert_eq(*result, 'H', "Expected 'H' at the returned position");
}

Test(test_strchr, TestCrash)
{
    char *str = "Test Crash";

    cr_assert(strchr(str, 2147489999) == strchr(str, 2147489999));
}

Test(test_strchr, character_found_in_middle)
{
    const char *str = "Hello, World";
    int c = 'o';

    char *result = strchr(str, c);

    cr_assert_not_null(result, "Expected not NULL for character found");
    cr_assert_eq(*result, 'o', "Expected 'o' at the returned position");
}

Test(test_strchr, FindWWithEmpty)
{
    char *str = "";

    cr_assert(strchr(str, 'A') == strchr(str, 'A'));
}

Test(test_strchr, character_found_at_end)
{
    const char *str = "Hello, World";
    int c = 'd';

    char *result = strchr(str, c);

    cr_assert_not_null(result, "Expected not NULL for character found");
    cr_assert_eq(*result, 'd', "Expected 'd' at the returned position");
}

Test(test_strchr, findW)
{
    char *str = "Hello World";

    cr_assert(strchr(str, 'x') == strchr(str, 'x'));

    cr_assert(strchr(str, 'H') == strchr(str, 'H'));
}
