#include <stdio.h>

float fahr_to_celsius(float fahr) {
	float celsius = 5.0 * (fahr - 32.0) / 9.0;
	return celsius;
}

/* Exercise 1-15 */
int main() {
	int lower, upper, step;
	float fahr;
	lower = 0;
	upper = 300;
	step = 20;

	for (fahr = lower; fahr <= upper; fahr += step)
		printf("%3.f %6.1f\n", fahr, fahr_to_celsius(fahr));
}