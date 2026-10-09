#include <stdio.h>
int main () {
    int a[6], min = 2147483647;
    for (int i = 1; i <= 5; min = min > a[i] ? a[i] : min, i++) scanf("%d", &a[i]);
    printf("%d", min);
    return 0;
}
