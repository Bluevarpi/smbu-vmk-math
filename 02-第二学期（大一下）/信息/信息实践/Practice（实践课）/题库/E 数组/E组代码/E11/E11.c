#include <stdio.h>

void quick_sort (int a[], int l, int r) {
	if (l >= r) return;
	int i = l, j = r, tmp = a[l], b[r + 1];
	for (int k = l; k <= r; k++) b[k] = a[k] % 10;
	while (i != j) {
		while (tmp % 10 <= b[j] && i < j) j--;
		if (i < j) a[i++] = a[j];
		while (b[i] <= tmp % 10 && i < j) i++;
		if (i < j) a[j--] = a[i];
	}
	a[i] = tmp;
	quick_sort(a, l, i - 1);
	quick_sort(a, i + 1, r);
}

int main () {
    int a[10];
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);
	quick_sort(a, 0, 9);
	for (int i = 0; i < 10; i++) printf("%d ", a[i]);
}
