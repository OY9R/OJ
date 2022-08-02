#include <stdio.h>
int main()
{
	int i,n,t=1;
	double s=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		s+=t*1.0/i;
		t=-t;
	}
	printf("%.4lf\n",s);
	return 0;
}