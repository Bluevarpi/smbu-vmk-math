#include <stdio.h>
int main () {
	int M = 0, m = 9, a;
	for (char c; (c = getchar()) != '\n'; M = M < a ? a : M, m = m > a ? a : m) a = c - '0';
	printf("%d", M - m);
	return 0;
}
