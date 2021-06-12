#include <stdio.h>

/*
	copy input to output
*/
int main() {

	//v1();
	v2();

	return 0;
}

// v1
int v1() {

	int c;

	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}

	return 0;
}

// v2
int v2() {

	int c;
	while ((c = getchar()) != EOF) {
		putchar(c);
	}
	printf("%s: %d\n", "eof", c);
}
