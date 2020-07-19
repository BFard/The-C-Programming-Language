#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);
void copy_and_remove(char to[], char from[], int len);

/* Exercise 1-18 */
int main() {
	int len;
	char line[MAXLINE];
	char modified_line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0) {
		copy_and_remove(modified_line, line, len);
		printf("%s", modified_line);
	}
	return 0;
}

/* getline: read a line into s; return length */
int getline(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy_and_remove: copy 'from' into 'to'; remove trailing space */
void copy_and_remove(char to[], char from[], int len) {
	int c, i;
	int found = 0;
	int to_len = 0;
	for (i = len - 1; i >= 0; --i) {
		c = from[i];
		if (!found && c != ' ' && c != '\t' && c != '\n') {
			found = 1;
			to[i] = c;
			to[i + 1] = '\n';
			to_len = i + 2;
		}
		else if (found)
			to[i] = c;
	}
	to[to_len] = '\0';
}
