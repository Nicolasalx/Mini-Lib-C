/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strncmp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern int strncmp(const char *s1, const char *s2, size_t n);

// est identique à strncmp sauf qu'elle ne compare que les n (au plus) premiers caractères de s1 et s2.

Test(test_strncmp, both_null_strings)
{
    const char *str1 = "";
    const char *str2 = "";

    int result = strncmp(str1, str2, 10);

    cr_assert_eq(result, 0, "Error");
}

Test(test_strncmp2, both_null_strings)
{
    const char *str1 = "abc";
    const char *str2 = "abc";

    int result = strncmp(str1, str2, 0);

    cr_assert_eq(result, 0, "Error");
}

Test(test_strncmp3, both_null_strings)
{
    const char *str1 = "abc111";
    const char *str2 = "abc222";

    int result = strncmp(str1, str2, 3);

    cr_assert_eq(result, 0, "Error");
}

Test(test_strncmp4, both_null_strings)
{
    const char *str1 = "abc111";
    const char *str2 = "abc555";

    int result = strncmp(str1, str2, 4);

    cr_assert_eq(result, -4, "Error");
}

Test(test_strncmp5, both_null_strings)
{
    const char *str1 = "abcdef";
    const char *str2 = "abcdef";

    int result = strncmp(str1, str2, 0);

    cr_assert_eq(result, 0, "Error");
}

Test(test_strncmp6, both_null_strings)
{
    const char *str1 = "a";
    const char *str2 = "z";

    int result = strncmp(str1, str2, 10);

    cr_assert_eq(result, -25, "Error");
}

Test(test_strncmp7, both_null_strings)
{
    const char *str1 = "z";
    const char *str2 = "a";

    int result = strncmp(str1, str2, 10);

    cr_assert_eq(result, 25, "Error");
}

Test(test_strncmp8, both_null_strings)
{
    const char *str1 = "";
    const char *str2 = "hello, world";

    int result = strncmp(str1, str2, 10);

    cr_assert_eq(result, -104, "Error");
}
