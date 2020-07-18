#include <stdio.h>

#define START 33 /* beginning of character range */
#define STOP 126 /* end of character range */

/* Exercise 1-14 */
main() {
	int c, i;
	int counts[STOP - START + 1];
	int max_count = 0, max_percentage;
	float total = 0;

	for (c = START; c <= STOP; ++c)
		counts[c - START] = 0;

	while ((c = getchar()) != EOF) {
		if (START <= c && c <= STOP) {
			++counts[c - START];
			++total;
			if (counts[c - START] > max_count)
				max_count = counts[c - START];
		}
	}

	max_percentage = 1 + 100 * max_count / total;
	for (c = START; c <= STOP; ++c) {
		float percentage = 100 * counts[c - START] / total;
		int xs = percentage + 1;
		if (percentage == 0)
			continue;
		printf("%c |", c, percentage);
		for (i = 0; i < max_percentage + 2; ++i) {
			if (i < xs)
				printf("x");
			else
				printf(" ");
		}
		printf("%.2f%%\n", percentage);
	}
}
