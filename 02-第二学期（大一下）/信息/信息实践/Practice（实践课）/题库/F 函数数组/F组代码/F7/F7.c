#include <stdio.h>

int compression(int a[], int b[], int N) {
    int cnt = 0, k = 0, tmp = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] == tmp) cnt++;
        else b[k++] = cnt, cnt = 1, tmp = a[i];
    }
	b[k++] = cnt;
    return k;
}

int main() {
    int a[100], b[100], N, i;
    printf("N = ");
    scanf("%d", &N);
    printf("a[%d] = ", N);
    for (i = 0; i < N; i++) scanf("%d", &a[i]);
    int size_of_b = compression(a, b, N);
    printf("b[%d] = ", size_of_b);
    for (i = 0; i < size_of_b; i++) printf("%d ", b[i]);
    return 0;
}
