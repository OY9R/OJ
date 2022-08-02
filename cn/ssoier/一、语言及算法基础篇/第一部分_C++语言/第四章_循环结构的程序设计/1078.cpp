#include <stdio.h>
int main()
{
	int i,n;
	double a=2,b=1,s=2,t;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		t=a;
		a=a+b;
		b=t;
		s+=a/b;
	}
	printf("%.4lf\n",s);
	return 0;
}