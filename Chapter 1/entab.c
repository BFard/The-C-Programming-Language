#include <stdio.h>

#define N 4

/* Exercise 1-21 */
int main() {
	int c, i, dist;
	int col = 0;

	while ((c = getchar()) != EOF)
		if (c == ' ') {
			dist = (col / N) * N + N - col;
			if (dist == 1) {
				putchar(c);
				++col;
				continue;
			}

			char temp[dist];
			int replace = 1, newline = 0;;
			temp[0] = ' ';

			for (i = 1; i < dist; ++i) {
				c = getchar();
				temp[i] = c;
				if (c == '\n') {
					replace = 0;
					newline = 1;
					dist = i + 1;
					break;
				}
				else if (c != ' ' && c != '\t')
					replace = 0;
			}

			if (replace)
				putchar('\t');
			else
				for(i = 0; i < dist; ++i)
					putchar(temp[i]);

			if (newline)
				col = 0;
			else
				col += dist;
		}
		else if (c == '\n') {
			putchar(c);
			col = 0;
		}
		else {
			putchar(c);
			++col;
		}
}
