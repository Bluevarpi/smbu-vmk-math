#include <stdio.h>

void sort_array(int size, int a[]) {
	for (int i = 0; i < size - 1; i++) for (int j = 0, tmp; j < size - i - 1; j++) if (a[j] > a[j + 1]) tmp = a[j], a[j] = a[j + 1], a[j + 1] = tmp;
}

int n, a[100000];

int main () {
    while (scanf("%d", &a[n++]) != EOF);
	sort_array(n, a);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
