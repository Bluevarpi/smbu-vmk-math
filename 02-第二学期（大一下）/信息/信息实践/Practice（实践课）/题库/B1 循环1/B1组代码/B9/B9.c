#include <stdio.h>
int main () {
	for (char c; (c = getchar()) != '\n';) if ((c - '0') % 2) { printf("NO"); return 0; }
	printf("YES");
	return 0;
}
