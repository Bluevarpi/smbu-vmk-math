#include <stdio.h>
int n, k, a[1000];
int main () {
	for (scanf("%d", &n); n; n /= 5) a[++k] = n % 5;
	if (k) while (k) printf("%d", a[k--]);
	else printf("0");
	return 0;
}
