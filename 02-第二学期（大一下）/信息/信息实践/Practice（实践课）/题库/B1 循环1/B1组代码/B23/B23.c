#include <stdio.h>
int main() {
    unsigned int a, b, c, d;
    scanf("%u%u%u%u", &a, &b, &c, &d);
    printf("%u", (d << 24) | (c << 16) | (b << 8) | a);
    return 0;
}
