#include <stdio.h>
long long m, n, sum;
int main () {
	for (scanf("%lld%lld", &m, &n); m <= n; m++) sum += m * m;
	printf("%lld", sum);
	return 0;
}
