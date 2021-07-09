#include <stdio.h>
#include <ctype.h>
#include "calc/getungetch.c"

#define SIZE 1000

// prototypes
void pointer_test();
void sw_ap(int*, int*);		// correct
//void test_get_int();
int getint(int*);
void pointers_and_arrays();
int str_len(char*);

void pointers_and_arrays() {
	int array[5] = {1,2,3,4,5};
	for (int i = 0; i < 5; i++) {
		printf("addr of array[%d]: %p\t", i, (array+i));
		printf("array[%d]: %d\n\n", i, *(array+i));
	}
}

void pointer_test() {
	int x = 1, y = 2, z[10];

	int *ip = &x;		// ip is a pointer to int that points to (the address of) x
	int *iq = &y;
	printf("The address of x is %p\n", ip);
	sw_ap(ip, iq);

	y = *ip;			// y is now 1
	printf("y is %d\n", y);

	*ip = 3;			// ip is now 3
	printf("ip has now been dereferenced to %d\n", *ip);

	ip = &z[0];			// ip now points to z[0]
	printf("ip is %p\n", ip);
}

void sw_ap(int *px, int *py) {
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}

// not functional, p. 86
/*void test_get_int() {
	int n, array[SIZE], getint(int*);
	for (n = 0; n < SIZE && (getint($array[n]) != EOF); n++);
}*/

/* getint: get next integer from input into *pn */
int getint(int *pn) {
	int c, sign;

	while (isspace(c = getch()));	// skip white space

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);		// not a number
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
	}

	for (*pn = 0; isdigit(c); c = getch()) {
		*pn = 10 * *pn + (c - '0');
	}

	*pn *= sign;

	if (c != EOF) {
		ungetch(c);
	}

	return c;
}

/* str_len: return length of string s */
int str_len(char *s) {		// str_len(char s[]) is also equivalent
	int n;
	for (n = 0; *s != '\0'; s++) {
		n++;
	}
	return n;
}
