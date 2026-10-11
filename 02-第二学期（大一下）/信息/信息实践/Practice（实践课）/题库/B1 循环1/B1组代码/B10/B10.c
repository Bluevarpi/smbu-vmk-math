#include <stdio.h>
int main () {
	for (char a, b = '/'; (a = getchar()) != '\n'; b = a) if (b >= a) { printf("NO"); return 0; }
	printf("YES");
	return 0;
}
