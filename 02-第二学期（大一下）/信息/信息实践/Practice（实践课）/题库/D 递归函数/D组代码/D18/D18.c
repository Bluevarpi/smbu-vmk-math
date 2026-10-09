#include <stdio.h>

void moveHanoi (int n, int a, int b, int c) {
	if (n == 1) printf("%d %d %d\n", n, a, c);
	else {
		moveHanoi(n - 1, a, c, b);
		printf("%d %d %d\n", n, a, c);
		moveHanoi(n - 1, b, a, c);
	}
}

int main () {
	int n;
	scanf("%d", &n);
	moveHanoi(n, 1, 2, 3);
	return 0;
}
