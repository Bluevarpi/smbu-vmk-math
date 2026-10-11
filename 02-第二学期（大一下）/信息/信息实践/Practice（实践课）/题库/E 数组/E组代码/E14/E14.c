#include <stdio.h>
int a[11], cnt[10000], max = -2147483645;
int main () {
	for (int i = 1; i <= 10 && scanf("%d", &a[i]); cnt[a[i]]++, i++) if (max < a[i]) max = a[i];
	for (int i = 0; i <= max; i++) if (cnt[i] > 1) printf("%d ", i);
	return 0;
}
