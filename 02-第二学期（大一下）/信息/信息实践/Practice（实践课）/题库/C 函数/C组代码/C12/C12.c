#include <stdio.h>
#include <math.h>
int main () {
	float x;
	scanf("%f", &x);
	printf("%.3f", sin(x * 3.1415926 / 180));
	return 0;
}
