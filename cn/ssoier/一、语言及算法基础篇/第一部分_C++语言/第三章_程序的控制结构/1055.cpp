#include<stdio.h>
int main() {
	int a, b = 0;
	scanf("%d", &a);
	if (a % 400 == 0)
		b = 1;
	else if (a % 4 == 0 && a % 100 != 0)
		b = 1;
	if (b == 1)
		printf("Y\n");
	else
		printf("N\n");
	return 0;
}
