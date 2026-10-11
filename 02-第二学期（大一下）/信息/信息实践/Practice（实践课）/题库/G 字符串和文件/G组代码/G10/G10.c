#include <stdio.h>
#include <string.h>
char a[1009], *tokens[1009], *ans;
int n, cnt, max = -2147483645, len, l;
int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    fgets(a, 1009, stdin);
    char *token = strtok(a, " ");
    for (len = strlen(a); len && a[len - 1] == '\n'; a[--len]='\0');
    while (token != NULL) tokens[++cnt] = token, token = strtok(NULL, " ");
    for(int i = 1; i <= cnt; i++) {
        l = strlen(tokens[i]);
        if (max < l) max = l, ans = tokens[i];
    }
    printf("%s",ans);
    return 0;
}
