#include "string.h"

size_t strlen(char* str) {
	size_t i = 0;
	while(str[i] != 0) {
		i++;
	}

	return i;
}

void* memcpy(void* restrict dstptr, void* restrict srcptr, size_t len) {
	uint8_t *dst = (uint8_t *) dstptr;
	uint8_t *src = (uint8_t *) srcptr;
	size_t i = 0;

	while(i < len) {
		dst[i] = src[i];
		i++;
	}

	return dst;
} 

void* memmove(void* dstptr, void* srcptr, size_t len) {
	uint8_t *dst = (uint8_t *) dstptr;
	const uint8_t *src = (const uint8_t *) srcptr;
	size_t i;

	if (dst < src) {
		for (i = 0; i < len; i++) {
			dst[i] = src[i];
		}

	} else {
		for (i = len; i > 0; i--) {
			dst[i] = src[i];
		}
		
	}

	return dstptr;
}

int	memcmp(const void* first, const void* second, size_t len) {
	const uint8_t *a = (const uint8_t *) first;
	const uint8_t *b = (const uint8_t *) second;
	size_t i = 0;
	for (i = 0; i < len; i++) {
		if (a[i] < b[i]) {
			return -1;
		} else if(a[i] > b[i]) {
			return 1;
		}
	}

	return 0; 
}

void* memset(void* mem, int value, size_t len) {
	uint8_t *dst = (uint8_t*) mem;
	size_t i = 0;

	while(i < len) {
		dst[i] = (uint8_t) value;
	}

	return mem;
}
