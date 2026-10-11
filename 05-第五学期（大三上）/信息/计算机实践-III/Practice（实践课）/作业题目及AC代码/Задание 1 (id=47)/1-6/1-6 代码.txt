#include <stdio.h>

int main() {
    unsigned int n;
    scanf("%u", &n);
    int cnt = 0;
    while (n > 0) n &= (n - 1), cnt++;
    printf("%d", cnt);
    return 0;
}