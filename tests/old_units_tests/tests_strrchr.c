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

Test(test_strrchr, findW)
{
    char *str = "Hello World";

    cr_assert(strrchr(str, 'x') == strrchr(str, 'x'));

    cr_assert(strrchr(str, 'H') == strrchr(str, 'H'));
}

Test(test_strrchr, TestAllEmpty)
{
    char *str = "";

    cr_assert(strrchr(str, '\0') == strrchr(str, '\0'));
}

Test(test_strrchr, testBackslachZero)
{
    char *str = "Hello, World!";

    cr_assert(strrchr(str, '\0') == strrchr(str, '\0'));
}

Test(test_strrchr, TestCrash)
{
    char *str = "Test Crash";

    cr_assert(strrchr(str, 2147489999) == strrchr(str, 2147489999));
}

Test(test_strrchr, FindWWithEmpty)
{
    char *str = "";

    cr_assert(strrchr(str, 'A') == strrchr(str, 'A'));
}

Test(test_strrchr, FindCharacterInMiddle)
{
    char *str = "Hello World";

    cr_assert(strrchr(str, 'o') == strrchr(str, 'o'));
}

Test(test_strrchr, FindLastCharacter)
{
    char *str = "Hello World";

    cr_assert(strrchr(str, 'd') == strrchr(str, 'd'));
}

Test(test_strrchr, FindFirstCharacter)
{
    char *str = "Hello World";

    cr_assert(strrchr(str, 'H') == strrchr(str, 'H'));
}

Test(test_strrchr, FindCharacterNotFound)
{
    char *str = "Hello World";

    cr_assert(strrchr(str, 'z') == strrchr(str, 'z'));
}

Test(test_strrchr, EmptyString)
{
    char *str = "";

    cr_assert(strrchr(str, 'a') == strrchr(str, 'a'));
}

Test(test_strrchr, FindNullTerminator)
{
    char *str = "Hello, World!";

    cr_assert(strrchr(str, '\0') == strrchr(str, '\0'));
}

Test(test_strrchr, LargeString)
{
    char str[10000];
    memset(str, 'a', sizeof(str));
    str[sizeof(str) - 1] = '\0';

    cr_assert(strrchr(str, 'a') == strrchr(str, 'a'));
}

Test(test_strrchr, FindCharacterWithMultipleOccurrence)
{
    char *str = "Hello World";

    cr_assert(strrchr(str, 'l') == strrchr(str, 'l'));
}

Test(test_strrchr, FindSpecialCharacter)
{
    char *str = "!@#$%^&*()";

    cr_assert(strrchr(str, '$') == strrchr(str, '$'));
}

Test(test_strrchr, FindCharacterWithLargeString)
{
    char str[1000000];
    memset(str, 'x', sizeof(str));
    str[sizeof(str) - 1] = '\0';

    cr_assert(strrchr(str, 'x') == strrchr(str, 'x'));
}

Test(test_strrchr, FindCharacterWithEscapedCharacter)
{
    char *str = "Hello \\ World";

    cr_assert(strrchr(str, '\\') == strrchr(str, '\\'));
}

Test(test_strrchr, FindNullInMiddle)
{
    char *str = "Hello\0World";

    cr_assert(strrchr(str, '\0') == strrchr(str, '\0'));
}

Test(test_strrchr, FindCharacterWithMixedCase)
{
    char *str = "Hello World";

    cr_assert(strrchr(str, 'o') == strrchr(str, 'o'));
}

Test(test_strrchr, FindNullTerminatorWithMixedCase)
{
    char *str = "Hello, World!";

    cr_assert(strrchr(str, '\0') == strrchr(str, '\0'));
}

Test(test_strrchr, FindCharacterWithUnicode)
{
    char *str = "Hello, Κόσμε!";

    cr_assert(strrchr(str, 'κ') == strrchr(str, 'κ'));
}

Test(test_strrchr, FindCharacterInReverseOrder)
{
    char *str = "Hello World";

    cr_assert(strrchr(str, 'r') == strrchr(str, 'r'));
}

Test(test_strrchr, FindCharacterWithNonAsciiCharacter)
{
    char *str = "Hello, Köln!";

    cr_assert(strrchr(str, 'ö') == strrchr(str, 'ö'));
}

Test(test_strrchr, FindCharacterAtEnd)
{
    char *str = "Hello World";

    cr_assert(strrchr(str, '\0') == strrchr(str, '\0'));
}

Test(test_strrchr, FindCharacterWithNumericString)
{
    char *str = "1234567890";

    cr_assert(strrchr(str, '5') == strrchr(str, '5'));
}

Test(test_strrchr, FindCharacterWithTabAndSpace)
{
    char *str = "Hello\tWorld ";

    cr_assert(strrchr(str, ' ') == strrchr(str, ' '));
}

Test(test_strrchr, FindCharacterWithNewline)
{
    char *str = "Hello\nWorld";

    cr_assert(strrchr(str, '\n') == strrchr(str, '\n'));
}

Test(test_strrchr, FindCharacterWithEmptyString)
{
    char *str = "";

    cr_assert(strrchr(str, 'a') == strrchr(str, 'a'));
}

Test(test_strrchr, FindCharacterWithSingleCharacterString)
{
    char *str = "H";

    cr_assert(strrchr(str, 'H') == strrchr(str, 'H'));
}

Test(test_strrchr, FindCharacterWithSpecialCharacter)
{
    char *str = "!@#$%^&*()";

    cr_assert(strrchr(str, '$') == strrchr(str, '$'));
}

Test(test_strrchr, FindCharacterWithRepeatingCharacters)
{
    char *str = "aaaaaaa";

    cr_assert(strrchr(str, 'a') == strrchr(str, 'a'));
}

Test(test_strrchr, FindCharacterWithControlCharacter)
{
    char *str = "Hello\x1bWorld";

    cr_assert(strrchr(str, '\x1b') == strrchr(str, '\x1b'));
}

Test(test_strrchr, FindCharacterWithRepeatedNullTerminators)
{
    char *str = "Hello\0\0\0World";

    cr_assert(strrchr(str, '\0') == strrchr(str, '\0'));
}
