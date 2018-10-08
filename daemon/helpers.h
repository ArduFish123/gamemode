/*

Copyright (c) 2017-2018, Feral Interactive
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
 * Neither the name of Feral Interactive nor the names of its contributors
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

 */

#pragma once

#include <stdio.h>
#include <string.h>
#include <sys/param.h>

/**
 * Value clamping helper, works like MIN/MAX but constraints a value within the range.
 */
#define CLAMP(lbound, ubound, value) MIN(MIN(lbound, ubound), MAX(MAX(lbound, ubound), value))

/**
 * Little helper to safely print into a buffer, returns a pointer into the buffer
 */
#define buffered_snprintf(b, s, ...)                                                               \
	(snprintf(b, sizeof(b), s, __VA_ARGS__) < (ssize_t)sizeof(b) ? b : NULL)

/**
 * Little helper to safely print into a buffer, returns a newly allocated string
 */
#define safe_snprintf(b, s, ...)                                                                   \
	(snprintf(b, sizeof(b), s, __VA_ARGS__) < (ssize_t)sizeof(b) ? strndup(b, sizeof(b)) : NULL)

/**
 * Helper function: Test, if haystack ends with needle.
 */
static inline const char *strtail(const char *haystack, const char *needle)
{
	char *pos = strstr(haystack, needle);
	if (pos && (strlen(pos) == strlen(needle)))
		return pos;
	return NULL;
}
