/*
 * Copyright 2021 the Pacemaker project contributors
 *
 * The version control history for this file may have further details.
 *
 * This source code is licensed under the GNU Lesser General Public License
 * version 2.1 or later (LGPLv2.1+) WITHOUT ANY WARRANTY.
 */

#ifndef MOCK_PRIVATE__H
#  define MOCK_PRIVATE__H

#include <sys/utsname.h>

/* This header is for the sole use of libcrmcommon_test. */

char *__real_getenv(const char *name);
char *__wrap_getenv(const char *name);

int __real_uname(struct utsname *buf);
int __wrap_uname(struct utsname *buf);

#endif  // MOCK_PRIVATE__H
