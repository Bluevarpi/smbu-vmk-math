#include <stdio.h>
int n, a[100];
int main () {
	for (char c; (c = getchar()) != '\n'; a[++n] = c - '0');
	while (n) printf("%d ", a[n--]);
	return 0;
}
