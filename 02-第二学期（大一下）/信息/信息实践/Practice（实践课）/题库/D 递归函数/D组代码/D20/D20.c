#include <stdio.h>
int main () {
	long long a, b, ans = 1ll;
	for (scanf("%lld%lld", &a, &b); b; a *= a, b >>= 1) if (b & 1) ans *= a;
	printf("%lld", ans);
	return 0;
}
