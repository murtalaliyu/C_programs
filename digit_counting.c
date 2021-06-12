#include <stdio.h>

/*
	count digits, white space, others
*/
int main() {
	count_digits_ws_others();
}

int count_digits_ws_others() {
	int c, ndigit[10], i, nwhite = 0, nother = 0;

	// initialize ndigit
	for (i = 0; i < 10; ++i) {
		ndigit[i] = 0;
	}

	// body
	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			++ndigit[c-'0'];
		} else if (c == ' ' || c == '\n' || c == '\t') {
			++nwhite;
		} else {
			++nother;
		}
	}

	// print ndigit
	printf("digits:");
	for (i = 0; i < 10; ++i) {
		printf(" %d", ndigit[i]);
	}
	printf("\tnwhite: %d\tnother: %d\n", nwhite, nother);

	// print horizontal histogram
	printf("\nhorizontal histogram\n");
	for (i = 0; i < 10; ++i) {
		printf("%d:", i);
		for (int j = 0; j < ndigit[i]; ++j) {
			printf(" *");
		}
		printf("\n");
	}

	// print vertical histogram

}
