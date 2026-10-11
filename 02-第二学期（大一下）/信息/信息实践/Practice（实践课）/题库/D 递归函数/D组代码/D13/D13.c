#include <stdio.h>
int n, cnt, k = 2;
int main () {
	for (scanf("%d", &n); k * k <= n; cnt = 0, k++) if (n % k == 0) while (n % k == 0) n /= k, printf("%d ", k);
	if (n > 1) printf("%d", n);
	return 0;
}
