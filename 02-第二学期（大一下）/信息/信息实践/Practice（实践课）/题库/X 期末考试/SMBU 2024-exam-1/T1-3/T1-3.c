#include <stdio.h>

int find_max_array (int n, int a[]) {
	int max = 0;
	for (int i = 0; i < n; i++) if (a[max] < a[i]) max = i;
	return a[max];
}

int main () {
	int a[10000], n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("%d", find_max_array(n, a));
	return 0;
}
