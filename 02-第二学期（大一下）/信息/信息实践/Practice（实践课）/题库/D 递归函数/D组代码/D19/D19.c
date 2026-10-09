#include <stdio.h>
int cnt;
int main () {
	for (char c; (c = getchar()) != '.';) if (c == 'a') cnt++;
	printf("%d", cnt);
	return 0;
}
