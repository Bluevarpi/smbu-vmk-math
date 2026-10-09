#include <stdio.h>

int main() {
    unsigned int n;
    int k;
    scanf("%u%d", &n, &k);
    printf("%u", (n >> k) | (n << (32 - k)));
    return 0;
}