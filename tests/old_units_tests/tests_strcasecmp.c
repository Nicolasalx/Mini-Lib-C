/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strcasecmp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern int strcasecmp(const char *s1, const char *s2);

// renvoie un pointeur sur la première occurrence du caractère c dans la chaîne s.

Test(test_strcasecmp, both_null_strings)
{
    const char *str1 = "";
    const char *str2 = "";

    int result = strcasecmp(str1, str2);

    cr_assert_eq(result, 0, "Error");
}

Test(test_strcasecmp2, both_null_strings)
{
    const char *str1 = "abc";
    const char *str2 = "abc";

    int result = strcasecmp(str1, str2);

    cr_assert_eq(result, 0, "Error");
}

Test(test_strcasecmp3, both_null_strings)
{
    const char *str1 = "abc111";
    const char *str2 = "ABC222";

    int result = strcasecmp(str1, str2);

    cr_assert_eq(result, -1, "Error");
}

Test(test_strcasecmp4, both_null_strings)
{
    const char *str1 = "AbC111";
    const char *str2 = "aBc555";

    int result = strcasecmp(str1, str2);

    cr_assert_eq(result, -4, "Error");
}

Test(test_strcasecmp5, both_null_strings)
{
    const char *str1 = "abcdef";
    const char *str2 = "ABCDEF";

    int result = strcasecmp(str1, str2);

    cr_assert_eq(result, 0, "Error");
}

Test(test_strcasecmp6, both_null_strings)
{
    const char *str1 = "a";
    const char *str2 = "Z";

    int result = strcasecmp(str1, str2);

    cr_assert_eq(result, -25, "Error");
}

Test(test_strcasecmp7, both_null_strings)
{
    const char *str1 = "Z";
    const char *str2 = "A";

    int result = strcasecmp(str1, str2);

    cr_assert_eq(result, 25, "Error");
}

Test(test_strcasecmp8, both_null_strings)
{
    const char *str1 = "";
    const char *str2 = "hello, world";

    int result = strcasecmp(str1, str2);

    cr_assert_eq(result, -104, "Error");
}

Test(test_strcasecmp8, snd_string_upper)
{
    const char *str1 = "abcd";
    const char *str2 = "abcde";

    int result = strcasecmp(str1, str2);

    cr_assert_eq(result, -101, "Error");
}
