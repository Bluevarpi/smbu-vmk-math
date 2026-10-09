#include <stdio.h>
int main () {
    for (int n; scanf("%d", &n) && n; n++) if (n & 1) printf("%d ", n);
    return 0;
}
