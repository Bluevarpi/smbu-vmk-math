#include <stdio.h>
int n, k = 1, tmp, cnt;
int main () {
	for (scanf("%d", &n); cnt < n; k++) for (tmp = k; tmp && cnt < n; tmp--, cnt++) printf("%d ", k);
	return 0;
}
