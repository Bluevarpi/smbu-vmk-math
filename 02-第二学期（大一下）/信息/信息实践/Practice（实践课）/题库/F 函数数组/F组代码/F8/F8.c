#include <stdio.h>
int n, a[1005], cnt[1005], min = 2147483645;
int main () {
	while (scanf("%d", &a[++n]) && a[n]) min = min > a[n] ? a[n] : min, cnt[a[n]]++;
	for (int i = min; ; i++) if (cnt[i] == 0) { printf("%d", i); return 0; }
}
