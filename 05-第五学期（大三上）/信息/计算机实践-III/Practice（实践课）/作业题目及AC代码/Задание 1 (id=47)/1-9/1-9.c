#include <stdio.h>

int main() {
    long long n, cnt = 0;
    scanf("%lld", &n);
    if (n > 797161) { printf("-1"); return 0; }
    while (n > 0) {
        if (n % 3 == 2) cnt++, n = (n + 1) / 3;
        else {
            if (n % 3 == 1) cnt++;
            n /= 3;
        }
    }
    printf("%d", cnt);
    return 0;
}