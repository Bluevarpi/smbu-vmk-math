#include <stdio.h>

int main(void) {
    int N, K, cnt = 0, tmp, n;
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; cnt += tmp == K, i++) for (tmp = 0, n = i; n; n >>= 1) tmp += !(n & 1);
    return printf("%d", cnt), 0;
}