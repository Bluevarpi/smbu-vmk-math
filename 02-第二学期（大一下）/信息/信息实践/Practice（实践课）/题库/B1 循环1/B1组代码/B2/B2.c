#include <stdio.h>
int main () {
	int a, b;
	for (scanf("%d%d", &a, &b); a <= b; a++) printf("%d ", a * a);
	return 0;
}
