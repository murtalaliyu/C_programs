#include <stdio.h>

#define IN 1		// inside a word
#define OUT 0		// outside a word

int main() {
	count_lines_words_chars();
}

/*
	count lines, words, and characters in input
*/
int count_lines_words_chars() {
	int c, nl = 0, nw = 0, nc = 0, prev = OUT, state = OUT;

	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n') {
			++nl;
		}

		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			++nw;
		}

		if (c != ' ' && c != '\n' && c != '\t') {
			putchar(c);
			prev = OUT;
		} else if (prev == OUT) {
			putchar('\n');
			prev = IN;
		}

		//printf("STATE: %d\n", state);
	}
	printf("nl:%d\tnw:%d\tnc:%d\n", nl, nw, nc);
}
