#include <stdio.h>

int main() {
    unsigned int n;
    scanf("%u", &n);
    printf("%u", n ^ 0xFF000000);
    return 0;
}