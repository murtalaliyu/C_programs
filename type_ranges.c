#include <stdio.h>
#include <limits.h>
#include <string.h>

// oct
#define VTAB '\013'		// ASCII vertical tab
#define BELL '\007'		// ASCII bell character

// hex
#define VTABH '\xb'
#define BELLH '\xb'

int main() {
	printf("CHAR_BIT: %d\n", CHAR_BIT);
	printf("CHAR_MAX: %d\n", CHAR_MAX);
	printf("SCHAR_MAX: %d\n", SCHAR_MAX);
	printf("CHAR_MIN: %d\n", CHAR_MIN);
	printf("INT_MAX: %d\n", INT_MAX);
	printf("INT_MIN: %d\n", INT_MIN);
	printf("LONG_MAX: %d\n", LONG_MAX);
	printf("SHRT_MAX: %d\n", SHRT_MAX);
	printf("UCHAR_MAX: %d\n", UCHAR_MAX);
	printf("UINT_MAX: %d\n", UINT_MAX);
	printf("ULONG_MAX: %d\n", ULONG_MAX);

	printf("oct \\007: %d\n", '\007');
	printf("hex \\x00f: %d\n", '\x00f');

	printf("symbolic: %d\n", BELLH);

	printf("string length: %d\n", strLen("hey"));

	return 0;
}

/* strLen: return length of s */
int strLen(char s[]) {
	int i;
	while (s[i] != '\0') {
		printf("%s\n", s[i]);
		++i;
	}
	return i;
}