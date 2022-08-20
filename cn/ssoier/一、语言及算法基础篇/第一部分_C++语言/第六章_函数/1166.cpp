#include <stdio.h>
#include <math.h>
double f(double x,double n)
{
    if(n==1)
        return sqrt(1+x);
    else
        return sqrt(n+f(x,n-1));
}
int main()
{
	double n,x;
    scanf("%lf%lf",&x,&n);
    printf("%.2lf\n",f(x,n));
    return 0;
}