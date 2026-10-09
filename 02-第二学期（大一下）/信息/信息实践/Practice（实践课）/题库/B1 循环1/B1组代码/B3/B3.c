#include <stdio.h>
int a, b, s;
int main () {
	for (scanf("%d%d", &a, &b); a <= b; a++) s += a * a;
	printf("%d ", s);
	return 0;
}
