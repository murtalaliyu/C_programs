#include <stdio.h>

#define NONBLANK '-'

/*
	count lines in input
*/
int main() {
	//count_blanks_tabs_newlines();
	replace_mult_blank_with_one();
	//replace_tabs_bkspc_bkslash();

	return 0;
}

int count_blanks_tabs_newlines() {
	int c, bk = 0, tb = 0, nl = 0;

	while ((c = getchar()) != EOF) {
		 if (c == ' ') {
			++bk;
		} else if (c == '\t') {
			++tb;
		} else if (c == '\n') {
			++nl;
		}
	}

	printf("# blanks: %d\t# tabs: %d\t# newlines: %d\n", bk, tb, nl);
	printf("This is %d\n", ' ');

	return 0;
}

int replace_mult_blank_with_one() {
	int c, lastc = NONBLANK;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (lastc != ' ') {
				putchar(c);
			}
		} else {
			putchar(c);
		}
		lastc = c;
	}

	return 0;
}

int replace_tabs_bkspc_bkslash() {
	int c = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			printf("\\t\n");
		} else if (c == '\b') {
			printf("\\b\n");
		} else if (c == '\\') {
			printf("\\\n");
		} else {
			putchar(c);
		}
	}

	return 0;
}
