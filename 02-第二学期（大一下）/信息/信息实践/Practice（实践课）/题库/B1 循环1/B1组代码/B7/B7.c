#include <stdio.h>
int n, cnt[10];
int main () {
	for (char c; (c = getchar()) != '\n'; cnt[c - '0']++);
	for (int i = 0; i <= 9; i++) if (cnt[i] > 1) { printf("YES"); return 0; }
	printf("NO");
	return 0;
}
