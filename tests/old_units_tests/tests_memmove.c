/*
** EPITECH PROJECT, 2024
** B-ASM-400-PAR-4-1-asmminilibc-nicolas1.alexandre
** File description:
** tests_memmove
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern void *memmove(void *dest, const void *src, size_t n);

Test(memmove, dest_before_src)
{
    char *dest1 = strdup("dest");
    char *dest2 = strdup("dest");

    char *src1 = strdup("Hello, src");
    char *src2 = strdup("Hello, src");

    char *result = memmove(dest1, src1, 4);
    char *result2 = memmove(dest2, src2, 4);

    cr_assert(strcmp(result, result2) == 0);

    cr_assert(strcmp(dest1, dest2) == 0, "dest1 and dest2 are not equal");
}

Test(memmove, src_before_src)
{
    char *src1 = strdup("Hello, src");
    char *src2 = strdup("Hello, src");

    char *dest1 = strdup("dest");
    char *dest2 = strdup("dest");

    char *result = memmove(dest1, src1, 4);
    char *result2 = memmove(dest2, src2, 4);

    cr_assert(strcmp(result, result2) == 0);

    cr_assert(strcmp(dest1, dest2) == 0, "dest1 and dest2 are not equal");
}

Test(memmove, src_null)
{
    char *src1 = strdup("");
    char *src2 = strdup("");

    char *dest1 = strdup("dest");
    char *dest2 = strdup("dest");

    char *result = memmove(dest1, src1, 1);
    char *result2 = memmove(dest2, src2, 1);

    cr_assert(strcmp(result, result2) == 0);

    cr_assert(strcmp(dest1, dest2) == 0, "dest1 and dest2 are not equal");
}

Test(memmove, dest_null)
{
    char *src1 = strdup("Hello, World!");
    char *src2 = strdup("Hello, World!");

    char *dest1 = strdup("");
    char *dest2 = strdup("");

    char *result = memmove(dest1, src1, 20);
    char *result2 = memmove(dest2, src2, 20);

    cr_assert(strcmp(result, result2) == 0);

    cr_assert(strcmp(dest1, dest2) == 0, "dest1 and dest2 are not equal");
}

Test(memmove, null)
{
    char *src1 = strdup("");
    char *src2 = strdup("");

    char *dest1 = strdup("");
    char *dest2 = strdup("");

    char *result = memmove(dest1, src1, 20);
    char *result2 = memmove(dest2, src2, 20);

    cr_assert(strcmp(result, result2) == 0);
    cr_assert(strcmp(dest1, dest2) == 0, "dest1 and dest2 are not equal");
}

Test(memmove, null_byte)
{
    char *src1 = strdup("\0");
    char *src2 = strdup("\0");

    char *dest1 = strdup("\0");
    char *dest2 = strdup("\0");

    char *result = memmove(dest1, src1, 20);
    char *result2 = memmove(dest2, src2, 20);

    cr_assert(strcmp(result, result2) == 0);

    cr_assert(strcmp(dest1, dest2) == 0, "dest1 and dest2 are not equal");
}
