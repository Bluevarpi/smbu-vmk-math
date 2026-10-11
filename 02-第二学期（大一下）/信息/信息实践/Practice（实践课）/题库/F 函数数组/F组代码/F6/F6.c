#include <stdio.h>

int is_two_same(int size, int a[]) {
	int cnt[100000], max = -2147483645;
	for (int i = 0; i < 100000; i++) cnt[i] = 0;
	for (int i = 0; i < size; cnt[a[i] + 5000]++, i++) if (max < a[i]) max = a[i];
	for (int i = 0; i <= max + 5000; i++) if (cnt[i] > 1) return 1;
	return 0;
}

int n, a[100000];

int main () {
	while (scanf("%d", &a[n++]) != EOF);
	printf(is_two_same(n, a) ? "YES" : "NO");
    return 0;
}
