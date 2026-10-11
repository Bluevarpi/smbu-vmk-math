#include <stdio.h>
int a[11];
int main () {
	for (int i = 1; i <= 10; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= 2; i++) for (int j = 5 * i; j >= 5 * i - 4; j--) printf("%d ", a[j]);
	return 0;
}
