#include <stdio.h>

#define OUT 0
#define IN_SINGLE_LINE_COMMENT 1
#define IN_MULTILINE_COMMENT 2
#define IN_QUOTES 3

/* Exercise 1-24 */
int main() {
	int c;
	int state = OUT;
	char quote_char;

	// A switch statement might be nicer here
	while ((c = getchar()) != EOF) {
		if (state == OUT) {
			if (c == '/') {
				c = getchar();
				if (c == '/') {
					state = IN_SINGLE_LINE_COMMENT;
				}
				else if (c == '*') {
					state = IN_MULTILINE_COMMENT;
				}
			}
			else {
				putchar(c);
				if (c == '"' || c == '\'') {
					quote_char = c;
					state = IN_QUOTES;
				}
			}
		}
		else if (state == IN_SINGLE_LINE_COMMENT) {
			if (c == '\n') {
				putchar(c);
				state = OUT;
			}
		}
		else if (state == IN_MULTILINE_COMMENT) {
			if (c == '*' && (c = getchar()) == '/') {
				state = OUT;
			}
		}
		else if (state == IN_QUOTES) {
			putchar(c);
			if (c == '\\') {
				c = getchar();
				putchar(c);
			}
			else if (c == quote_char) {
				state = OUT;
			}
		}
	}

	return 0;
}