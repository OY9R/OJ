#include <stdio.h>
#include <math.h>
int is_prime(int n)
{
	int i,k;
	k=sqrt(n);
	for(i=2;i<=k;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}
int main()
{
    int i,n,found=0;
    scanf("%d",&n);
    for(i=2;i<=n-2;i++)
    {
    	if(is_prime(i) && is_prime(i+2))
    	{
    		printf("%d %d\n",i,i+2);
    		found=1;
		}
	}
	if(!found)
		printf("empty");
    return 0;
}