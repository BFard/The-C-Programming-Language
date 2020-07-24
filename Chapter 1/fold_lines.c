#include <stdio.h>

#define MAXLINE 1000
#define TABSIZE 4
#define N 41 // Assume N >= 2
#define EXCESS 10

int getline(char s[], int lim);
int copy_between(char to[], char from[], int start, int end);

/* Exercise 1-23 */
int main() {
	int c, i, len, temp_len, col;
	int increased, found;
	int nb_before_ind, nb_before_col, nb_after_ind;
	char line[MAXLINE], temp[MAXLINE];
	char to_print[N];

	len = getline(line, MAXLINE);
	while (len > 0) {
		nb_before_ind = nb_before_col = nb_after_ind = -1;
		col = 1;

		for (i = 0; i < len - 1; ++i) {
			c = line[i];

			if (c == '\t') {
				col = (col - 1) / TABSIZE * TABSIZE + TABSIZE + 1;
			}
			else {
				++col;

				if (c != ' ' && col <= N) {
					nb_before_ind = i;
					nb_before_col = col;
				}
				else if (c != ' ') {
					nb_after_ind = i;
					break;
				}
			}
		}

		if (col <= N) {
			printf("%s", line);
			len = getline(line, MAXLINE);
			continue;
		}

		if (nb_before_col == N) {
			increased = found = 0;
			for (i = 1; i <= EXCESS + 1; ++i) {
				c = line[nb_before_ind + i];
				if (c == ' ' || c == '\t' || c == '\n') {
					nb_before_ind += i - 1;
					increased = 1;
					break;
				}
			}

			if (increased) {
				for (i = nb_before_ind + 1; i < len - 1; ++i) {
					c = line[i];
					if (c != ' ' && c != '\t') {
						nb_after_ind = i;
						found = 1;
						break;
					}
				}

				if (!found) {
					nb_after_ind = -1;
				}
			}
		}

		copy_between(to_print, line, 0, nb_before_ind);
		printf("%s\n", to_print);

		if (nb_after_ind == -1) {
			len = getline(line, MAXLINE);
		}
		else {
			len = copy_between(line, line, nb_after_ind, len - 1);
		}
	}
	return 0;
}

int getline(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF
		 && c != '\n'; ++i) {
			s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

int copy_between(char to[], char from[], int start, int end) {
	for (int i = start; i <= end; ++i) {
		to[i - start] = from[i];
	}

	to[end - start + 1] = '\0';
	return end - start + 1;
}