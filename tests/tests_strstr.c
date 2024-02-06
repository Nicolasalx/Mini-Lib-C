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

