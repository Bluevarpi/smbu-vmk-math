#include <stdio.h>

int main() {
    int n, max = -2147483648, cnt = 0, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num > max) max = num, cnt = 1;
        else if (num == max) cnt++;
    }
    printf("%d", cnt);
    return 0;
}