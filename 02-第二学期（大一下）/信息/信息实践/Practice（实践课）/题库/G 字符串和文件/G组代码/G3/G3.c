#include <stdio.h>
#include <string.h>
int main () {
	char s[102];
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
    while (len && s[len - 1] == '\n') s[--len] = '\0';
    for (int i = 0; i < len - 1; i++) if (s[i] == s[len - 1]) printf("%d ", i);
    return 0;
}
