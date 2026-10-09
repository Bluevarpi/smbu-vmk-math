#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char s[1005];
	int stack[1005], top = 0, a, b;
    while (scanf("%s", s) == 1 && *s != '.') if (*s >= '0' && *s <= '9') stack[top++] = atoi(s);
	else b = stack[--top], a = stack[--top], stack[top++] = *s == '+' ? a + b : *s == '-' ? a - b : *s == '*' ? a * b : a / b;
	return printf("%d", stack[0]), 0;
}