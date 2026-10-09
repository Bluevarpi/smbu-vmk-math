#include <stdio.h>

int f(char *a, char *b) {
    int i, j = 0, p[10005];
    for (i = 1; a[i]; p[i++] = j += a[i] == a[j]) while (j && a[i] != a[j]) j = p[j - 1];
    for (i = j = 0; b[i]; j += b[i++] == a[j]) while (j && b[i] != a[j]) j = p[j - 1];
    return j;
}

int main() {
    char a[10005], b[10005];
    return scanf("%s%s", a, b), printf("%d %d", f(a, b), f(b, a)), 0;
}