#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("%.3f", max(max(a, b), c) / (max(a+b, max(b, c)) * max(a, max(b, b+c))));
	return 0; 
}