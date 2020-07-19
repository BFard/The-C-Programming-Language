#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);
void reverse(char s[]);

/* Exercise 1-19 */
int main() {
	int len;
	char line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0) {
		reverse(line);
		printf("%s", line);
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

/* reverse: reverse the string s in place */
void reverse(char s[]) {
	int len, i, c;
	for (len = 0; s[len] != '\n'; ++len)
		;
	for (i = 0; i < len / 2; ++i) {
		c = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = c;
	}
}