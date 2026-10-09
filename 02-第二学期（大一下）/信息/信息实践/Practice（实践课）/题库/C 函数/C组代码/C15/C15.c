#include <stdio.h>
int n;
int main () {
	for (char c[1000]; scanf("%c", &c[n]) && c[n] != '\n'; n++) if (n) if (c[n - 1] >= c[n]) { printf("NO"); return 0; }
	printf("YES");
	return 0;
}
