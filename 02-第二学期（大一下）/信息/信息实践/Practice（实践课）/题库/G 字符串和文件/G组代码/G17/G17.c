#include <stdio.h>
#include <string.h>

void swap (char *a, char *b) {
    char c = *a;
    *a = *b, *b = c;
}

char a[1002];
int len, flag;

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    fgets(a, 1002, stdin);
    for (len = strlen(a); len && a[len - 1]=='\n'; a[--len] = '\0');
    if (len & 1) flag = 1;
    for (int i = 0; i < len - flag; i++) {
        if (a[i] == ' ') continue;
        for (int j = i + 1; j < len; j++) {
            if (a[j] != ' ') {
                swap(&a[i], &a[j]);
                i = j;
                break;
            }
        }  
    }
    for (int i = 0; i < len; i++) printf("%c", a[i]);
    return 0;
}
