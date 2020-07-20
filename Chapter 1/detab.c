#include <stdio.h>

#define N 4

/* Exercise 1-20 */
int main() {
	int c, i, col, spaces;

	for (col = 0; (c = getchar()) != EOF; ++col)
		if (c == '\t') {
			spaces = (col / N) * N + N - col;
			col += spaces - 1;
			for (i = 0; i < spaces; ++i)
				putchar(' '); 
		}
		else if (c == '\n') {
			putchar(c);
			col = -1;
		}
		else
			putchar(c);
	return 0;
}
