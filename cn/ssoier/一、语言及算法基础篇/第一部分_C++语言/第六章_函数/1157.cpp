#include <stdio.h>
#include <math.h>
int isprime(int n)
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
    int i,j;
 
    for(i=6; i<=100; i+=2)
    {
    	for(j=2;j<=i/2;j++)
    	{
            if(isprime(j) && isprime(i-j))
            {
                printf("%d=%d+%d\n",i,j,i-j);
                break;
            }
        }
    }
    return 0;
}