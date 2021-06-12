#include <stdio.h>

#define LOWER 0		// lower limit of table
#define UPPER 300	// upper limit
#define STEP 20		// step size

/*
	p. 12
	print Fahrenheit-Celsius table
	for fahr = 0, 20, ... , 300
*/
int main() {

	//one();
	two();

	return 0;
}

one() {
	printf("one\n");

	float fahr, celsius;
	float lower, upper, step;

	lower = 0;		// lower limite of temperature scale
	upper = 300;	// upper limit
	step = 20;		// step size

	printf("%s \t %s\n", "celsius", "fahr");
	printf("---------------------------\n");

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%.0f \t %.1f\n", fahr, celsius);
		fahr += step;
	}

	return 0;
}

two() {
	printf("two\n");

	for (int fahr = LOWER; fahr <= UPPER; fahr += STEP) {
		printf("%3d \t %5.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}

	return 0;
}
