#include <stdio.h>
int main () {
    for (char c; (c = getchar()) != '.';) {
    	if ('a' <= c && c <= 'z') c += 'A' - 'a';
		else if ('A' <= c && c <= 'Z') c -= 'A' - 'a';
		putchar(c);
	}
    return 0;
}
