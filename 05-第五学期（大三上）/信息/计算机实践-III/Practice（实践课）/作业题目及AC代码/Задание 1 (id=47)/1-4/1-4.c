#include <stdio.h>

int main() {
    unsigned int n;
    int k;
    scanf("%u%d", &n, &k);
    printf("%u", n & ((1U << k) - 1));
    return 0;
}