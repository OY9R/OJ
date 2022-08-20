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
    int i,s;
    scanf("%d",&s);
    for(i=s/2; i>=2; i--)
    {
        if(isprime(i) && isprime(s-i))
        {
            printf("%d\n",i*(s-i));
            break;
        }
    }
    return 0;
}