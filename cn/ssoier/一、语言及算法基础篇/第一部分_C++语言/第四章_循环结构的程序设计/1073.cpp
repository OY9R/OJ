#include <stdio.h>
#include <math.h>
 
int main()
{
	int n;
	int p;
	double x,y;
	double t,tot;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf%lf%d",&x,&y,&p);
		t=sqrt(x*x+y*y);
		tot+=(t/50)*2+1.5*p;
	}
	printf("%d\n",(int)ceil(tot));
	return 0;
}