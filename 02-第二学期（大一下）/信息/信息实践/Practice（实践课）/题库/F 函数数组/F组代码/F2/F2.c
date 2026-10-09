#include <stdio.h>

void sort_even_odd(int n, int a[]) {
    int b[100], c[100], k = 0, l = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) b[k++] = a[i];
        else c[l++] = a[i];
    }
    for (int i = 0; i < k; i++) a[i] = b[i];
    for (int i = 0; i < l; i++) a[k + i] = c[i];
}

int n, a[100];

int main () {
    while (scanf("%d", &a[n++]) != EOF);
	sort_even_odd(n, a);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
