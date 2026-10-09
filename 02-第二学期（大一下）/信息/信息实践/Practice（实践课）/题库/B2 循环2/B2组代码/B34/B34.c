#include <stdio.h>
#define ll long long

ll Factorial (ll n) {
	return n == 0 ? 1 : n * Factorial(n - 1);
}

int main() {
    ll n;
	scanf("%lld", &n);
	printf("%lld", Factorial(n));
    return 0;
}
