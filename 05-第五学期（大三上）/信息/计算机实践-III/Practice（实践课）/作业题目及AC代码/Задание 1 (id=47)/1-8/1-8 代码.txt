#include <stdio.h>

int main() {
    int n, tmp, num = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++, num ^= tmp) scanf("%d", &tmp);
    printf("%d", num);
    return 0;
}