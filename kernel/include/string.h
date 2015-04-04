#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdint.h>

size_t strlen(char* str);

int	memcmp(const void* first, const void* second, size_t len);
void* memset(void* mem, int value, size_t len);
void* memmove(void* dstptr, void* srcptr, size_t len);
void* memcpy(void* __restrict dstptr, void* __restrict srcptr, size_t len);

#endif
