#include <stdio.h>
int a[26][26], tr, cnt;
int main () {
	for (int i = 1; i <= 5; tr += a[i][i], i++) for (int j = 1; j <= 5; j++) scanf("%d", &a[i][j]);
	for (int i = 1; i <= 5; i++) for (int j = 1; j <= 5; j++) if (a[i][j] > 0 && a[i][j] > 1.0 * tr / 5) cnt++;
	printf("%d", cnt);
	return 0;
}
