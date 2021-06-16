#include <stdio.h>
#include <string.h>
#include <ctype.h>

// prototypes
int strindex(char[], char[]);
double atof(char[]);
void printd(int);
void qsort(int[], int, int);
void swap(int[], int, int);


/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++);
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

/*
Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.
*/

/* atof: convert string s to double */
double atof(char s[]) {
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++);	// skip white space

	sign = (s[i] == '-') ? -1 : 1;
	
	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

	return sign * val / power;
}

/*
Exercise 4-2. Extend atof to handle scientific notation of the form
 123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent. 
*/

/*
Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
the modulus (%) operator and provisions for negative numbers.

Exercise 4-4. Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack. 

Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in
Appendix B, Section 4.

Exercise 4-6. Add commands for handling variables. (It's easy to provide twenty-six variables
with single-letter names.) Add a variable for the most recently printed value.

Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch?

Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify
getch and ungetch accordingly.

Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
what their properties ought to be if an EOF is pushed back, then implement your design.

Exercise 4-10. An alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach. 

Exercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint: use an internal
static variable.
*/

/* printd: print n in decimal */
void printd(int n) {
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10) {
		printd(n/10);
	}
	putchar(n % 10 + '0');
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right) {
	int i, last;

	if (left >= right) {		// do nothing if array contains fewer than two elements
		return;
	}

	swap(v, left, (left + right)/2);	// move partition elem to v[0]

	last = left;

	for (i = left+1; i <= right; i++) {	// partition
		if (v[i] < v[left]) {
			swap(v, ++last, i);			// restore partition elem
		}
	}

	swap(v, left, last);		// restore partition element

	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j) {
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/*
Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert
an integer into a string by calling a recursive routine.

Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the
string s in place. 
*/

/*
Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t.
(Block structure will help.) 
*/
