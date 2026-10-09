#include <stdio.h>
int n, p, k, a[100];
int main () {
	for (scanf("%d%d", &n, &p); n; n /= p) a[++k] = n % p;
	if (k) while (k) printf("%d", a[k--]);
	else printf("0");
	return 0;
}
