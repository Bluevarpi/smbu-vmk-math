#include <stdio.h>
float n, s, i = 1;
int main () {
	for (scanf("%f", &n); i < n; i += 0.1) s += i * i;
	printf("%.1f", s);
	return 0;
}
