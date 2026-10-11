#include <stdio.h>

void quick_sort (int a[], int l, int r) {
	if (l >= r) return;
	int i = l, j = r, tmp = a[l];
	while (i != j) {
		while (tmp <= a[j] && i < j) j--;
		if (i < j) a[i++] = a[j];
		while (a[i] <= tmp && i < j) i++;
		if (i < j) a[j--] = a[i];
	}
	a[i] = tmp;
	quick_sort(a, l, i - 1);
	quick_sort(a, i + 1, r);
}

int main () {
    int a[10];
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);
	quick_sort(a, 0, 4);
	for (int i = 0; i <= 4; i++) printf("%d ", a[i]);
	quick_sort(a, 5, 9);
	for (int i = 9; i >= 5; i--) printf("%d ", a[i]);
}
