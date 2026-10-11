#include <stdio.h>
int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld", n * (n + 1) * (n + 2) * (3 * n + 1) / 12);
    return 0;
}
