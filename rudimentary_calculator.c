#include <stdio.h>

/* 
	p. 15
	rudimentary calculator
*/
int main() {
	
	int sum, v;
	sum = 0;

	while (scanf("%d", &v) == 1) {
		printf("\t%d\n", sum += v);
	}

	return 0;
}
