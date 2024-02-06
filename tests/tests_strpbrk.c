/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** tests_strpbrk
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

// recherche la première occurrence dans la chaîne s de l'un quelconque des caractères de la chaîne accept.

extern char *strpbrk(const char *s, const char *accept);

Test (test_strpbrk, test)
{
    char *string = "admin";
    char *substring = "a";

    char *result = strpbrk(string, substring);

    cr_assert(result, "admin");
}

Test (test_strpbrk2, test)
{
    char *string = "admin";
    char *substring = "VDEa";

    char *result = strpbrk(string, substring);

    cr_assert(result, "admin");
}

Test (test_strpbrkx, test)
{
    char *string = "admin";
    char *substring = "d";

    char *result = strpbrk(string, substring);

    cr_assert(result, "dmin");
}

Test (test_strpbrk3, test)
{
    char *string = "admin";
    char *substring = "m";

    char *result = strpbrk(string, substring);

    cr_assert(result, "min");
}

Test (test_strpbrk4, test)
{
    char *string = "admin";
    char *substring = "n";

    char *result = strpbrk(string, substring);

    cr_assert(result, "n");
}

Test (test_strpbrk5, test)
{
    char *string = "admin";
    char *substring = "";

    char *result = strpbrk(string, substring);

    cr_assert(result == NULL);
}

Test (test_strpbrk6, test)
{
    char *string = "admin";
    char *substring = "X";

    char *result = strpbrk(string, substring);

    cr_assert(result == NULL);
}
