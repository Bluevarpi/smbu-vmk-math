#include <stdio.h>

int count_bigger_abs(int n, int a[]) {
	int cnt = 0, max = -2147483645;
	for (int i = 0; i < n; i++) if (max < a[i]) max = a[i];
	for (int i = 0; i < n; i++) if (max + a[i] < 0) cnt++;
	return cnt;
}

int n, a[100000];

int main () {
	while (scanf("%d", &a[n]) != EOF) n++;
	printf("%d", count_bigger_abs(n, a));
	return 0;
}
