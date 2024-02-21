/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strcmp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern int strcmp(const char *s1, const char *s2);

// compare les deux chaînes s1 et s2. Elle renvoie un entier négatif, nul, ou positif, si s1 est respectivement inférieure, égale ou supérieure à s2

Test(test_strcmp, both_null_strings)
{
    const char *str1 = "";
    const char *str2 = "";

    int result = strcmp(str1, str2);

    cr_assert_eq(result, 0, "Error");
}

Test(test_strcmp, one_null_string)
{
    const char *str1 = "hello";
    const char *str2 = "hell";

    int result = strcmp(str1, str2);

    cr_assert_eq(result, 111, "Error");
}

Test(test_strcmp, equal_strings1)
{
    const char *str1 = "hello";
    const char *str2 = "hello";

    int result = strcmp(str1, str2);

    cr_assert_eq(result, 0, "Error");
}

Test(test_strcmp, equal_strings)
{
    const char *str1 = "hell";
    const char *str2 = "hello";

    int result = strcmp(str1, str2);

    cr_assert_eq(result, -111, "Error");
}

Test(test_strcmp, different_strings)
{
    const char *str1 = "hello";
    const char *str2 = "hellx";

    int result = strcmp(str1, str2);

    cr_assert(result, -9, "Error");
}

Test(test_strcmp, longer_first_string)
{
    const char *str1 = "a";
    const char *str2 = "x";

    int result = strcmp(str1, str2);

    cr_assert_eq(result, -23, "Error");
}

Test(test_strcmp, longer_second_string)
{
    const char *str1 = "x";
    const char *str2 = "a";

    int result = strcmp(str1, str2);

    cr_assert_eq(result, 23, "Error");
}
