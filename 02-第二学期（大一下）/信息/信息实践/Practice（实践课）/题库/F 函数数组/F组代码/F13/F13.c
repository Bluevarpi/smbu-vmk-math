#include <stdio.h>

int count_between(int from, int to, int size, int a[]) {
	int cnt[10000], sum = 0;
	for (int i = 0; i < 10000; i++) cnt[i] = 0;
	for (int i = 0; i < size; i++) cnt[a[i] + 5000]++;
	for (int i = from; i <= to; i++) sum += cnt[i + 5000];
	return sum;
}

int n, a[100000], l, r;

int main () {
	printf("from = ");
	scanf("%d", &l);
	printf("to = ");
	scanf("%d", &r);
	printf("a[] = ");
	while (scanf("%d", &a[n]) != EOF) n++;
	printf("%d", count_between(l, r, n, a));
	return 0;
}
