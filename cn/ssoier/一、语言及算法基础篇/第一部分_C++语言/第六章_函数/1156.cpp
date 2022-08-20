#include<bits/stdc++.h>
using namespace std;
//求arctan(x)，最后一项大于等于lim 
double arctan(double x, double lim)
{
    double sum = 0, num = x, den = 1;//num:分子 den:分母 
    int sign = 1;//符号
    while(num/den >= lim)
    {
    	sum += sign * num / den;
    	num *= x*x;
    	den += 2;
    	sign = -sign;
	}
    return sum;
} 
int main()
{
    cout << fixed << setprecision(10) << 6*arctan(1/sqrt(3), 1e-6); 
    return 0;
}