#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    for (char c; (c = getchar()) != '.'; putchar(c)) {
        if (c >= 'a' && c <= 'z') c = ((c - 'a' + n) % 26) + 'a';
        else if (c >= 'A' && c <= 'Z') c = ((c - 'A' + n) % 26) + 'A';
    }
	putchar('.');
    return 0;
}