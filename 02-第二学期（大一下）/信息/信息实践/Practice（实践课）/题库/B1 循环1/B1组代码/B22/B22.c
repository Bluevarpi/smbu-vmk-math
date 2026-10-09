#include <stdio.h>
unsigned int N, k, max, val, i;
int main() {
    scanf("%u%d", &N, &k);
    for (; i <= 32 - k; i++) val = (N >> i) & (0xFFFFFFFF >> (32 - k)), max = max < val ? val : max;
	printf("%u", max);
    return 0;
}
