#include <stdio.h>
#include <stdlib.h>

#define IN 1
#define OUT 0

/* Exercise 1-13 with vertical histogram */
main() {
	int c, i, j, state = OUT;
	int length_cap = 20;
	int * counts = malloc(sizeof(int) * length_cap);
	int curr_length;
	int max_count = 0;

	for (i = 0; i < length_cap; ++i)
		counts[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				if (curr_length >= length_cap) {
					int old_length_cap = length_cap;
					length_cap = curr_length + 1;
					counts = realloc(counts, sizeof(int) * length_cap);
					for (i = old_length_cap; i < length_cap; ++i)
						counts[i] = 0;
				}
				++counts[curr_length];
			}
			state = OUT;
		}
		else if (state == OUT) {
			state = IN;
			curr_length = 1;
		}
		else {
			++curr_length;
		}
	}

	for (i = 1; i < length_cap; ++i) {
		if (counts[i] > max_count)
			max_count = counts[i];
	}

	printf("Word Lengths\n");
	for (i = 41; i > 0; --i) {
		for (j = 1; j < length_cap; ++j) {
			if (i <= 1 + 40 * counts[j] / max_count && counts[j] > 0)
				printf(" xx ");
			else
				printf("    ");
		}
		printf("\n");
	}

	for (j = 1; j < length_cap; ++j)
		printf("----");
	printf("\n");
	for (j = 1; j < length_cap; ++j)
		printf("%3d|", j);
}
