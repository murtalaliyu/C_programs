#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 	// maximum input line length
#define VOID 0			// void constant

// prototypes
int getLine(char[], int);
int copy(char[], char[]);

// print the longest input line
int main2() {
	int len;				// current line length
	int max = 0;			// maximum length seen so far
	char line[MAXLINE];		// current input line
	char longest[MAXLINE];	// longest line saved here

	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0) {	// there was a line
		printf("longest: %s\n", longest);
		printf("length: %d\n", max);
	}

	return 0;
}

// getLine: read a line into s, return length. does not include newline
int getLine(char s[], int lim) {
	int c, i;
	for (i = 0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

// copy: copy 'from' and 'to'; assume to is big enough
int copy(char to[], char from[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
	return VOID;
}

/*
Write a function reverse(s) that reverses the character string s. 
Use it to write a program that reverses its input a line at a time.
*/
/*int reverse(char s[], int max) {
	char res[max];
	for (int i = 0; s[i] != '\0' && s[i] != '\n'; ++i) {
		res[max-i-1] = s[i];
	}
	printf("reversed: %s", res);
	return VOID;
}*/
