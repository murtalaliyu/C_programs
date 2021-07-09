// import C libraries
#include <stdio.h>
#include <string.h>

// import files
#include "longest_line.c"
#include "chp_2.c"
#include "chp_3.c"
#include "chp_4.c"
#include "chp_5.c"

// symbolic constants
#define VOID 0
#define MAXLINE 1000

// macros
#define square(x) (x) * (x)	// You should absolutely always put macro arguments between parentheses
#define dprint(expr)	printf(#expr " = %g\n", expr)
#define sw_ap(t,x,y)	({	\
	t temp = x;	\
	x = y;	\
	y = temp;	\
})

// prototypes
int one();
int two();
int run_squeeze();
int run_altsqueeze();
int run_bitcount();
int run_binsearch();
int run_reverse();
int run_pattern();
int run_rud_calc();
void run_qsort();
void run_square_macro();
void run_print_division_macro();
void run_sw_ap_macro();
void run_str_len();

// external variables
char pattern[] = "ould";	// pattern to search for

int main() {
	
	//one();
	//two();
	//run_squeeze();
	//run_altsqueeze();

	//printf("getbits: %d\n", getbits(5,4,3));

	//run_bitcount();
	//run_binsearch();

	//count_digits();
	//run_reverse();
	//run_pattern();
	//run_rud_calc();
	//printd(123);
	//run_qsort();
	//run_square_macro();
	//run_print_division_macro();
	//run_sw_ap_macro();
	run_str_len();
}

void run_str_len() {
	printf("%d\n", str_len("hello, world"));	// string constant
	char array[] = {'h', 'e', 'l', 'l', '0'};
	printf("%d\n", str_len(array));		// not sure why this is not 5 (says 8)
	char *ptr = array;
	printf("%d\n", str_len(ptr));

	*ptr = *array;
	printf("%c\n", *ptr);

	int a[] = {5,4,3,2,1};
	int *p = a+2;	// &a[2] is also equivalent
	printf("%p\n", p);
	printf("%d\n", *p);
}

// sw_ap macro
void run_sw_ap_macro() {
	char x = 'a', y = 'b';
	sw_ap(char,x,y);
	printf("char:\tx=%c, y=%c\n", x,y);

	int m = 1, n = 2;
	sw_ap(int,m,n);
	printf("int:\tm=%d, n=%d\n", m,n);
}

// print division macro
void run_print_division_macro() {
	double x = 10, y = 5;
	dprint(x/y);
}

// square macro
void run_square_macro() {
	int z = 5;
	printf("square: %d", square(z+1));
}

// recursive quick sort
void run_qsort() {
	int arr[] = {8,6,2,7,4,1};
	qsort(arr, 0, 5);
	for (int i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}
}

// rudimentary calculator
int run_rud_calc() {
	double sum, atof(char[]);
	char line[MAXLINE];
	int getLine(char line[], int max);

	sum = 0;
	while (getLine(line,MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));

	return 0;
}

int run_pattern() {
	char line[MAXLINE];
	int index, found = 0;

	while (getLine(line,MAXLINE) > 0)
		if ((index=strindex(line,pattern)) >= 0) {
			printf("%s", line);
			printf("index: %d\n", index);
			found++;
		}
	printf("found: %d", found);

	return found;
}

int run_reverse() {
	int c, len;
	char line[MAXLINE];

	len = getLine(line,MAXLINE);
	reverse(line);
	printf("reversed: %s\n", line);

	return VOID;
}

int one() {
	int c, len, val;
	char line[MAXLINE];

	len = getLine(line,MAXLINE);
	val = htoi(line);

	printf("The value of %s is %d\n", line, val);

	return VOID;
}

int two() {
	char s[MAXLINE], t[MAXLINE/2];

	getLine(s,MAXLINE);
	getLine(t,MAXLINE/2);
	strcat(s,t);
	printf("new s: %s\n", s);

	return VOID;
}

int run_squeeze() {
	char input[MAXLINE];
	getLine(input,MAXLINE);
	squeeze(input,'b');
	printf("squeezed: %s", input);

	return VOID;
}

int run_altsqueeze() {
	char s1[MAXLINE], s2[10];
	getLine(s1,MAXLINE);
	getLine(s2,10);
	altsqueeze(s1,s2);
	printf("alt squeezed: %s\n", s1);

	return VOID;
}

int run_bitcount() {
	int c;
	while ((c=getchar()) != EOF) {
		int res = bitcount((unsigned)c);
		printf("%d\n", res);
	}
	return VOID;
}

/*int run_binsearch() {
	int arr = {2,4,6,7,9,29,45,46,49,50,51};
	printf("binsearch: %d\n", binsearch(9,arr,10));
	return VOID;
}*/

