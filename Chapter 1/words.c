#include <stdio.h>

#define IN 1
#define OUT 0

/* Exercise 1-10 */
main () {
	int c, state;

	state = IN;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			putchar('\n');
		}
		putchar(c);
	}
}