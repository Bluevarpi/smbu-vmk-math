#include <stdio.h>
int n, a[100000], cnt;
int main () {
	while (scanf("%d", &a[++n]) && a[n]) cnt += 1 - a[n] & 1;
	printf("%d", cnt);
	return 0;
}
