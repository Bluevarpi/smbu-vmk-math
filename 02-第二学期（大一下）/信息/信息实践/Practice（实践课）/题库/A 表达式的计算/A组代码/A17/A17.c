#include <stdio.h>
int main () {
    int m;
    scanf("%d", &m);
    if (m == 3 || m == 4 || m == 5) printf("spring");
    if (m == 6 || m == 7 || m == 8) printf("summer");
    if (m == 9 || m == 10 || m == 11) printf("autumn");
    if (m == 12 || m == 1 || m == 2) printf("winter");
    return 0;
}
