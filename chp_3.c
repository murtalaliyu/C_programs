#include <stdio.h>
#include <string.h>

#define VOID 0			// void constant

// prototypes
int binsearch(int, int[], int);
int count_digits();
int shellsort(int[], int);
int reverse(char[]);
int itoa(int, char[]);
int trim(char[]);


/* Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and
measure the difference in run-time. 
*/
// binsearch: find x in v[0] <= v[1] <= ... <= v[n-1]
int binsearch(int x, int v[], int n) {
	int low=0, high=n-1, mid=0;
	while (low <= high) {
		mid=(low+high)/2;
		if (x < v[mid]) {
			high = mid+1;
		} else if (x > v[mid]) {
			low = mid+1;
		} else {
			return mid;
		}
	}
	return -1;
}

/* with case conditions */
int count_digits() {
	int c, i, nwhite=0, nother=0, ndigit[10];

	// init ndigit
	for (i = 0; i < 10; i++) {
		ndigit[i] = 0;
	}

	// body
	while ((c=getchar()) != EOF) {
		switch (c) {
			case '0': case '1': case '2': case '3': case '4': 
			case '5': case '6': case '7': case '8': case '9': 
				ndigit[c-'0']++;
				break;
			case ' ':
			case '\n':
			case '\t':
				nwhite++;
				break;
			default:
				nother++;
				break;
		}
	}

	// prints
	printf("digits =");
	for (i = 0; i < 10; i++)
		printf(" %d", ndigit[i]);
	printf(", wspace = %d , other = %d\n", nwhite, nother);

	return VOID;
}

/*
Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
a function for the other direction as well, converting escape sequences into the real characters. 
*/

/* shellsort: sort v[0]...v[n-1] into increasing order */
int shellsort(int v[], int n) {
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i++) {
			for (j = i-gap; j >= 0 && v[j] > v[j+gap]; j-=gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
		}
	}
	return VOID;
}

/* reverse: reverse string s in place */
int reverse(char s[]) {
	int c, i, j;
	for (int i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	return VOID;
}

/* 
Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally
*/
int expand(char s1[], char s2[]) {


	return VOID;
}

/* itoa: convert n to characters in s */
int itoa(int n, char s[]) {
	int i=0, sign;

	if ((sign = n) < 0)		// record sign
		n = -n;

	do {		// generate digits in reverse order
		s[i++] = n % 10 + '0';		// get next digit
	} while ((n /= 10) > 0);		// delete it

	if (sign < 0) 
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);

	return VOID;
}

/*
Exercise 3-4. In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why
not. Modify it to print that value correctly, regardless of the machine on which it runs.
*/

/*
Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s. 
*/

/*
Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough. 
*/

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[]) {
	int n;

	for (n = strlen(s)-1; n >= 0; n--)
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	s[n+1] = '\0';

	return n;
}