#pragma once

#include <string.h>
#include <stdlib.h>

static inline void explicit_bzero(void *s, size_t n) {
    memset(s, 0, n);
    __asm__ __volatile__ ("" :: "r"(s) : "memory");
}

void *__memmove_chk(void *dest, const void *src, size_t n, size_t dest_len);
void *__memcpy_chk(void *dest, const void *src, size_t n, size_t dest_len);
