#include <stdio.h>
int main () {
    int a[6], min = 1;
    for (int i = 1; i <= 5; min = a[min] > a[i] ? i : min, i++) scanf("%d", &a[i]);
	printf("%d", a[min]);
    return 0;
}
