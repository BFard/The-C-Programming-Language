#include <stdio.h>

/* Exercise 1-9 */
main () {
	int c, prev_space = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (prev_space)
				continue;
			prev_space = 1;
		}
		else {
			prev_space = 0;
		}
		putchar(c);
	}
}
