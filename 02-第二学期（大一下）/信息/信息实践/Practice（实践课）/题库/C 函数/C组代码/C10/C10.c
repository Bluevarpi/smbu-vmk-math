#include <stdio.h>
int n, k = 2;
int main () {
	for (scanf("%d", &n); k * k <= n; k++) while (n % k == 0) n /= k, printf("%d ", k);
	if (n > 1) printf("%d", n);
	return 0;
}
