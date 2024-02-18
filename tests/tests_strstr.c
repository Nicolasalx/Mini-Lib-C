/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** tests_strstr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>


extern char *strstr(const char *meule_de_foin, const char *aiguille);

Test (test_strstr1, test)
{
    const char *meule_de_foin = "Hello, world!";
    const char *aiguille = "o";

    const char *result = strstr(meule_de_foin, aiguille);

    cr_assert(result, "o, world!");
}

Test (test_strstr2, test)
{
    const char *meule_de_foin = "Hello, world!";
    const char *aiguille = "H";

    const char *result = strstr(meule_de_foin, aiguille);

    cr_assert(result, "Hello, world!");
}

Test (test_strstr3, test)
{
    const char *meule_de_foin = "Hello, world!";
    const char *aiguille = "worl";

    const char *result = strstr(meule_de_foin, aiguille);

    cr_assert(result, "world!");
}

Test (test_strstr4, test)
{
    const char *meule_de_foin = "";
    const char *aiguille = "worl";

    const char *result = strstr(meule_de_foin, aiguille);

    cr_assert(result == NULL);
}

Test (test_strstr5, test)
{
    const char *meule_de_foin = "Hello, world!";
    const char *aiguille = "";

    const char *result = strstr(meule_de_foin, aiguille);

    cr_assert(result, "Hello, world!");
}

Test(strstr, basic)
{
    const char *s1 = "test";
    const char *s2 = "st";

    cr_assert_not_null(strstr(s1, s2));

    cr_assert_str_eq(strstr(s1, s2), strstr(s1, s2));
}

Test(strstr, empty_string)
{
    char *s1 = strdup("");
    char *s2 = strdup("st");

    cr_assert(strstr(s1, s2) == strstr(s1, s2));
    cr_assert(strstr(s2, s1) == strstr(s2, s1));
}

Test(strstr, null_byte)
{
    char *s1 = strdup("");
    char *s2 = strdup("\0");

    cr_assert(strstr(s1, s2) == strstr(s1, s2));
    cr_assert(strstr(s2, s1) == strstr(s2, s1));
    cr_assert(strstr(s1, s1) == strstr(s1, s1));
}

Test(strstr, full_null)
{
    char *str1 = strdup("");
    char *str2 = strdup("");

    cr_assert(strstr(str1, str2) == strstr(str1, str2));
}

Test(strstr, not_found)
{
    char *str1 = strdup("Hello, world!");
    char *str2 = strdup("lloa");

    cr_assert(strstr(str1, str2) == NULL);
}

Test(strstr, not_found_2)
{
    char *str1 = strdup("Hello, world!");
    char *str2 = strdup("a");

    cr_assert(strstr(str1, str2) == NULL);
}

Test(strstr, not_found_3)
{
    char *str1 = strdup("");
    char *str2 = strdup("a");

    cr_assert(strstr(str1, str2) == NULL);
}

Test(strstr, not_found_4)
{
    char *str1 = strdup("a");
    char *str2 = strdup("");

    cr_assert(strstr(str1, str2), "a");
}