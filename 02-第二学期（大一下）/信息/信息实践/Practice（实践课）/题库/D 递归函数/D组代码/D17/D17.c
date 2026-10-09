#include <stdio.h>

int akkerman (int m, int n) {
	return m ? n ? akkerman(m - 1, akkerman(m, n - 1)) : akkerman(m - 1, 1) : n + 1;
}

int main () {
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%d", akkerman(m, n));
	return 0;
}
