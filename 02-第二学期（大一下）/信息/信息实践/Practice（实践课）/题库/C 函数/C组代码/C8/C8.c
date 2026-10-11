#include <stdio.h>
int main () {
	for (char c; (c = getchar()) != '.';) putchar('a' <= c && c <= 'z' ? c - 32 : c);
	return 0;
}
