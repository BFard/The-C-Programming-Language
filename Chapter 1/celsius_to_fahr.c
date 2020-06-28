#include <stdio.h>

/* Print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300; floating-point version */
main() {
	printf("\nCelsius-Fahrenheit table\n");

	float fahr, celsius;
	int lower, upper, step;

	lower = 0; /* lower limit of temperature table */
	upper = 300; /* upper limit of temperature table */
	step = 20; /* step size */

	celsius = lower;
	while (celsius <= upper) {
		fahr = 9.0/5.0 * celsius + 32.0;
		printf("%3.0f %6.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
