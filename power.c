#include <stdio.h>

// prototype
int power(int, int);

/* test power function */
int main() {
	for (int i = 0; i < 10; ++i) {
		printf("i:%d\tpower(2,%d):%d\t\tpower(-3,%d):%d\n", i, i, power(2,i), i, power(-3,i));
	}
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n) {
	int p;
	for (p = 1; n > 0; --n) {
		p *= base;
	}
	return p;
}
