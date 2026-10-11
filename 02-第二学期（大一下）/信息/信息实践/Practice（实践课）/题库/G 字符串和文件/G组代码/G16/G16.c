#include <stdio.h>
#include <string.h>
char a[1002];
int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    fgets(a, 1002, stdin);
    int len = strlen(a);
    while (len && a[len - 1] == '\n') a[--len] = '\0';
    for (int i = 0; i < len; i++) {
        if (a[i] == 'L' && a[i + 1] == 'i' && a[i + 2] == 'n' && a[i + 3] == 'g') {
            printf("Cao");
            i += 3;
        }
        else printf("%c", a[i]);
    }
    return 0;
}
