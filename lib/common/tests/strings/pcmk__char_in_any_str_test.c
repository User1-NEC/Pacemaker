/*
 * Copyright 2020-2021 the Pacemaker project contributors
 *
 * The version control history for this file may have further details.
 *
 * This source code is licensed under the GNU Lesser General Public License
 * version 2.1 or later (LGPLv2.1+) WITHOUT ANY WARRANTY.
 */

#include <crm_internal.h>

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

static void
empty_list(void **state)
{
    assert_false(pcmk__char_in_any_str('x', NULL));
    assert_false(pcmk__char_in_any_str('\0', NULL));
}

static void
null_char(void **state)
{
    assert_true(pcmk__char_in_any_str('\0', "xxx", "yyy", NULL));
    assert_true(pcmk__char_in_any_str('\0', "", NULL));
}

static void
in_list(void **state)
{
    assert_true(pcmk__char_in_any_str('x', "aaa", "bbb", "xxx", NULL));
}

static void
not_in_list(void **state)
{
    assert_false(pcmk__char_in_any_str('x', "aaa", "bbb", NULL));
    assert_false(pcmk__char_in_any_str('A', "aaa", "bbb", NULL));
    assert_false(pcmk__char_in_any_str('x', "", NULL));
}

int main(int argc, char **argv)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(empty_list),
        cmocka_unit_test(null_char),
        cmocka_unit_test(in_list),
        cmocka_unit_test(not_in_list),
    };

    cmocka_set_message_output(CM_OUTPUT_TAP);
    return cmocka_run_group_tests(tests, NULL, NULL);
}

