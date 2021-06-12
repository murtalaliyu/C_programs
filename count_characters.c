#include <stdio.h>

/*
	count characters in input
*/
int main() {
	//v1();
	v2();

	return 0;
}

int v1() {
	long nc;

	nc = 0;
	while (getchar() != EOF) {
		++nc;
	}
	printf("%ld\n", nc);

	return 0;
}

int v2() {
	double nc;

	for (nc = 0; getchar() != EOF; ++nc);
		
	printf("%.0f\n", nc);

	return 0;
}
