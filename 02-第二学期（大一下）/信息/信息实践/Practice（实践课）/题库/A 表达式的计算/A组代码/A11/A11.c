#include <stdio.h>
int main () {
    int a[6], max = -2147483647, min = 2147483647;
    for (int i = 1; i <= 5; max = max < a[i] ? a[i] : max, min = min > a[i] ? a[i] : min, i++) scanf("%d", &a[i]);
    printf("%d", max + min);
    return 0;
}
