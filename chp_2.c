#define VOID 0
#define MAXNUM 1000

// prototypes
int atoi(char[]);
int lower(int);
int htoi(char[]);
int squeeze(char[],int);
int stringcat(char[], char[]);
int any(char[], char[]);
unsigned getbits(unsigned, int, int);
int bitcount(unsigned);


/* atoi: convert s to integer */
int atoi(char s[]) {
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
		n = 10 * n + (s[i] - '0');
	}
	return n;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c) {
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

/* Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F.
COMPLETE */
#define YES 1
#define NO 0
int htoi(char s[]) {
	int hexdigit, i = 0, inhex, n = 0;

	if (s[i] == '0') {
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}

	inhex = YES;

	for (;inhex==YES;++i) {
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] = '0';
		else if (s[i] >= 'a' && s[i] <= 'f') 
			hexdigit = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F') 
			hexdigit = s[i] - 'A' + 10;
		else 
			inhex = NO;

		if (inhex == YES)
			n = 16 * n + hexdigit;
	}

	return n;
}

/* squeeze: delete all c from s
COMPLETE */
int squeeze(char s[], int c) {
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++) {
		printf("i: s[%d]:%d\n", i,s[i]);
		printf("j: s[%d]:%d\n\n", j,s[j]);
		if (s[i] != c) {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';

	return VOID;
}

/* strcat: concatenate t to the end of s; s must be big enough
COMPLETE */
int stringcat(char s[], char t[]) {
	int i=0, j=0;
	while (s[i] != '\0')	// find end of s
		i++;
	while ((s[i++] = t[j++]) != '\0');	// copy t

	return VOID;
}

/* Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2. 
*/
int altsqueeze(char s1[], char s2[]) {
	int k;
	for (int i = 0; s1[i] != '\0'; i++) {
		k=0;
		for (int j = 0; s2[j] != '\n'; j++) {
			if (s1[i] != s2[j]) {
				s1[k++] = s1[i];
			}
		}
	}

	return VOID;
}

/* Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.) 
*/
int any(char s1[], char s2[]) {

	return VOID;
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p+1-n)) & ~(~0 << n);
}

/*
Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.

Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.

Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions. 
*/

/* bitcount: count 1 bits in x */
int bitcount(unsigned x) {
	int b;
	for (b = 0; x != 0; x >>= 1) {
		if (x & 01) {
			b++;
		}
	}
	return b;
}