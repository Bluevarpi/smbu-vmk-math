#include <stdio.h>
#include <string.h>
int main () {
    char s[102];
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
    while (len && s[len - 1] == '\n') s[--len] = '\0';
    printf("%s, %s, %s %d", s, s, s, len);
    return 0;
}
