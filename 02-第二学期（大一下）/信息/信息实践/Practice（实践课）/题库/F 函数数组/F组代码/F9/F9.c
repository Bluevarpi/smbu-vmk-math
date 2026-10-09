#include <stdio.h>

void swap_negmax_last(int size, int a[]) {
	int max = -2147483645, k = -1, tmp;
	for (int i = 0; i < size; i++) if (a[i] < 0 && max < a[i]) max = a[i], k = i;
	if (k == -1) return;
	tmp = a[k], a[k] = a[size - 1], a[size - 1] = tmp;
}

int n, a[100000];

int main () {
	while (scanf("%d", &a[n]) && a[n]) n++;
	swap_negmax_last(n, a);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	return 0;
}
