#include <stdio.h>
#include <math.h>
int main () {
	float x;
	scanf("%f", &x);
	printf("%.3f", cos(x * 3.1415926 / 180));
	return 0;
}
