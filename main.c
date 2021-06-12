#include <stdio.h>
#include <string.h>

#include "longest_line.c"
#include "chp_2.c"
#include "chp_3.c"
#include "chp_4.c"

#define VOID 0
#define MAXLINE 1000

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

