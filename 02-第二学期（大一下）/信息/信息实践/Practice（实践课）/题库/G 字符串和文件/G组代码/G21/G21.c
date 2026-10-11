#include <stdio.h>
#include <string.h>
#include <math.h>
char a[10002], b[10002];
int n, cnt, len, delta;
int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (fgets(b, 10002, stdin)) strcat(a,b);
    for (len = strlen(a); len && a[len - 1] == '\n'; a[--len] = '\0');
    for (int i = 0; i < len; i++) if(a[i] == '*') cnt++;
    delta = sqrt(1 + 8 * cnt), n = (delta - 1) / 2;
    if (cnt == 0 || delta * delta != 1 + 8 * cnt) { printf("NO"); return 0; }
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) printf(" ");
        for(int j = 1; j <= i; j++) printf("* ");
        puts("");
    }
    return 0;
}
