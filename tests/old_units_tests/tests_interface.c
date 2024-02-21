/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** tests_interface
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/hooks.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define SIZE_BAR (30)

static int count_test = 1;

ReportHook(PRE_ALL)(struct criterion_test_set *tests)
{
    (void) tests;
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    printf("\n----------------------------------------------------\n"
            "\t\t    Test Results\n"
            "----------------------------------------------------\n\n");
}

ReportHook(POST_ALL)(struct criterion_global_stats *stats)
{
    double percentage_pass = ((double) stats->tests_passed / (double) stats->nb_tests) * 100.0;
    printf("\nPass rate: [");
    char color_code[] = "\e[91m";
    if (percentage_pass >= 75.0) {
        strcpy(color_code, "\e[92m");
    } else if (percentage_pass >= 25.0) {
        strcpy(color_code, "\e[93m");
    }
    for (int i = 0; i < SIZE_BAR; ++i) {
        if (i < (int) (percentage_pass * ((double) SIZE_BAR / 100.0))) {
            printf("%s█\e[0m", color_code);
        } else {
            printf("\e[0;37m▒\e[0m");
        }
        usleep(30000);
    }
    printf("] \e[1m%s%.1f%%\e[0m\n\n", color_code, percentage_pass);
    printf("----------------------------------------------------\n");
    printf("\e[1mTested: \e[94m%ld\e[0m\e[1m"
    " | Passing: \e[92m%ld\e[0m\e[1m | Failing: \e[91m%ld\e[0m\e[1m | Crashing: \e[91m%ld\e[0m\n",
    stats->nb_tests, stats->nb_tests - (stats->asserts_failed + stats->tests_skipped + stats->tests_crashed),
    stats->asserts_failed, stats->tests_skipped + stats->tests_crashed);
    printf("----------------------------------------------------\n\n");
}


ReportHook(POST_FINI)(struct criterion_test_stats *test)
{
    if (test->test_status == CR_STATUS_PASSED) {
        printf("Test %3d : [\e[92mPASS\e[0m] in %.2f sec\n", count_test, test->elapsed_time);
    } else if (test->test_status == CR_STATUS_FAILED) {
        printf("Test %3d : [\e[91mFAIL\e[0m] \e[1m%s\e[0m:\e[91m%d\e[0m: %s\n",
        count_test, test->file, test->asserts->line, test->asserts->message);
        printf("\t   [\e[94m----\e[0m] \e[96m%s\e[0m::\e[94m%s\e[0m\n", test->test->category, test->test->name);
    } else {
        printf("Test %3d : [\e[91mCRASH\e[0m] \e[93m%s %s %s\e[0m:\e[91m%d\e[0m \e[1m%s\e[0m\n",
        count_test, test->file, test->test->category, test->test->name, test->asserts->line, test->asserts->message);
    }
    ++ count_test;
}

ReportHook(TEST_CRASH)(struct criterion_test_stats *test)
{
    printf("Test %3d : [\e[91mCRASH\e[0m] \e[1m%s\e[0m: \e[1;91m%s\e[0m.\n"
        "\t   [\e[94m----\e[0m] \e[96m%s\e[0m::\e[94m%s\e[0m\n",
        count_test, test->file, strsignal(test->signal), test->test->category, test->test->name);
    ++ count_test;
}
