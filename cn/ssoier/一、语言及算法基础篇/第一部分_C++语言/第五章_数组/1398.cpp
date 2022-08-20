#include <stdio.h>
int calc(int x)
{
	if(x%70==0)
        return x/70;
    else
        return x/70+1;
}
int main()
{
    int i,n,a;
    double sum=0;

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        sum+=calc(a);
    }
    printf("%.1lf\n",sum/10.0);
    return 0;
}