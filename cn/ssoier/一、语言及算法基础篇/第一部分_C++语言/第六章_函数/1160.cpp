#include <stdio.h>
int rev(int n)
{
	int t,res=0;
	t=n;
	while(n)
	{
		res=res*10+n%10;
		n/=10;
	}
	return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",rev(n));
	return 0;
}