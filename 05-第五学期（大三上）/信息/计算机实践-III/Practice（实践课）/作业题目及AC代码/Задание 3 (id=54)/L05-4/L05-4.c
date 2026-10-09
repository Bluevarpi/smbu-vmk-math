#include <stdio.h>
#include <string.h>

int main(void) {
    char s[105]; int seen[1000] = {0}, cnt = 0, len;
    if (scanf("%104s", s) != 1) return 0;
    for (int i = 0; i < (len = strlen(s)); i++) if (s[i] != '0') for (int j = i + 1; j < len; j++) for (int k = j + 1; k < len; k++) cnt += !seen[(s[i] - '0') * 100 + (s[j] - '0') * 10 + s[k] - '0']++;
    return printf("%d", cnt), 0;
}