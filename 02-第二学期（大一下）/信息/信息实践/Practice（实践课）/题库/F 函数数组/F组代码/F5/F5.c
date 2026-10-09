#include <stdio.h>

int find_max_array(int size, int a[]) {
	int max = -2147483645;
	for (int i = 0; i < size; i++) if (max < a[i]) max = a[i];
	return max;
}

int n, a[100000];

int main () {
	while (scanf("%d", &a[n++]) != EOF);
	printf("%d", find_max_array(n, a));
    return 0;
}
