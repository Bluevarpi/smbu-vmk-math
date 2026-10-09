#include <stdio.h>
int main () {
    int n;
    for (scanf("%d", &n); n > 0; n -= 2) printf("%d ", n);
    return 0;
}
