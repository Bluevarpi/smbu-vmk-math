#include <stdio.h>

int main() {
    unsigned int n, max = 0, tmp;
    int k;
    scanf("%u%d", &n, &k);
    for (int i = 0; i <= 32 - k; i++) {
        tmp = (n >> i) & ((1U << k) - 1);
        if (tmp > max) max = tmp;
    }
    printf("%u", max);
    return 0;
}