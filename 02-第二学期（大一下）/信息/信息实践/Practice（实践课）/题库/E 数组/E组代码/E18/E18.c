#include <stdio.h>
int main () {
	int n, m = 2;
	for (scanf("%d", &n); m <= 9; m++) printf("%d %d\n", m, n / m);
	return 0;
}
