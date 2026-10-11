#include <stdio.h>
int cnt;
int main () {
	for (char c; (c = getchar()) != '.';) {
		cnt = c == ' ' ? cnt + 1 : 0;
		if (cnt < 2) putchar(c);
	}
	return 0;
}
