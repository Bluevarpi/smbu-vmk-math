#include <stdio.h>
int main () {
    float a, b, c, d;
    scanf("%f%f%f%f", &a, &b, &c, &d);
    printf("%.2f %.2f", (b - d) / (a - c), (a * d - b * c) / (a - c));
    return 0;
}
