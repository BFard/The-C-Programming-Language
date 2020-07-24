#include <stdio.h>

#define OUT 0
#define IN_SINGLE_LINE_COMMENT 1
#define IN_MULTILINE_COMMENT 2
#define IN_QUOTES 3

/* Exercise 1-25 */
int main() {
	int c, line_num = 1, char_num = 1, state = OUT;
	int parens, brackets, braces;
	char quote_char;

	parens = brackets = braces = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			++line_num;
			char_num = 1;
			if (state == IN_SINGLE_LINE_COMMENT) {
				state = OUT;
			}
		}
		else if (state == OUT) {
			if (c == '/') {
				c = getchar();
				++char_num;
				if (c == '*') {
					state = IN_MULTILINE_COMMENT;
				}
				else if (c == '/') {
					state = IN_SINGLE_LINE_COMMENT;
				}
			}
			else if (c == '\'' || c == '"') {
				quote_char = c;
				state = IN_QUOTES;
			}
			else if (c == '(') {
				++parens;
			}
			else if (c == '[') {
				++brackets;
			}
			else if (c == '{') {
				++braces;
			}
			else if (c == ')') {
				--parens;
				if (parens < 0) {
					parens = 0;
					printf("Extra close paren at line %d character %d\n", line_num, char_num);
				}
			}
			else if (c == ']') {
				--brackets;
				if (brackets < 0) {
					brackets = 0;
					printf("Extra close bracket at line %d character %d\n", line_num, char_num);
				}
			}
			else if (c == '}') {
				--braces;
				if (braces < 0) {
					braces = 0;
					printf("Extra close brace at line %d character %d\n", line_num, char_num);
				}
			}
		}
		else if (state == IN_MULTILINE_COMMENT) {
			if (c == '*') {
				c = getchar();
				++char_num;
				if (c == '/') {
					state = OUT;
				}
				else if (c == '\n') {
					++line_num;
					char_num = 1;
				}
			}
		}
		else if (state == IN_QUOTES) {
			if (c == '\\') {
				c = getchar();
				++char_num;
				if (c == '\n') {
					++line_num;
					char_num = 1;
				}
			}
			else if (c == quote_char) {
				state = OUT;
			}
		}
		++char_num;
	}

	if (parens > 0) {
		printf("Extra open paren(s) detected.\n");
	}
	if (brackets) {
		printf("Extra open bracket(s) detected.\n");
	}
	if (braces > 0) {
		printf("Extra open brace(s) detected.\n");
	}

	return 0;
}
