#include <stdio.h>
int n, sum, pdt, a = 22, tmp;
int main () {
	for (scanf("%d", &n); a <= n; a++) {
		tmp = a, sum = 0, pdt = 1;
		while (tmp) sum += tmp % 10, pdt *= tmp % 10, tmp /= 10;
		if (sum == pdt) printf("%d ", a);
	}
	return 0;
}
