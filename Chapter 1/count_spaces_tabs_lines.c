#include <stdio.h>

/* Exercise 1-8 */
main() {
	int c, ns, nt, nl;

	ns = 0;
	nt = 0;
	nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++ns;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nl;
	}
	printf("Spaces: %d Tabs: %d Newlines: %d\n", ns, nt, nl);
}