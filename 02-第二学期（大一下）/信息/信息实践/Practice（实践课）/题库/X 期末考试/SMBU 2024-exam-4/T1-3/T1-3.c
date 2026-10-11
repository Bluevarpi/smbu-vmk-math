#include <stdio.h>
int main () {
	for (int n, t, s = 0, p = 1; scanf("%d", &n) && n; s = 0, p = 1) {
		for (t = n; t; t /= 10) s += t % 10, p *= t % 10;
		if (s == p) printf("%d ", n);
	}
	return 0;
}
