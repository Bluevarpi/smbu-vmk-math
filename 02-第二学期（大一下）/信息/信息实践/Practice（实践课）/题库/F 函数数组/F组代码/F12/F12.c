#include <stdio.h>

void change_max_min(int size, int a[]) {
	int min = 2147483645, max = -2147483645, k = 0, l = 0, tmp;
	for (int i = 0; i < size; i++) {
		if (min > a[i]) min = a[i], k = i;
		if (max < a[i]) max = a[i], l = i;
	}
	tmp = a[k], a[k] = a[l], a[l] = tmp;
}

int n, a[100000];

int main () {
	while (scanf("%d", &a[n]) != EOF) n++;
	change_max_min(n, a);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	return 0;
}
