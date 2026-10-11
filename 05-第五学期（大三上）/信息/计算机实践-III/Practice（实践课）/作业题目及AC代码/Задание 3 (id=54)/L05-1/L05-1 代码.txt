#include <stdio.h>

int main(void) {
    int n;
	unsigned int x, res = 0;
    for (scanf("%d", &n); n-- > 0; res ^= x) scanf("%u", &x);
    return printf("%u\n", res), 0;
}