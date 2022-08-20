#include <stdio.h>
#include <math.h>
int palindrome(int n)
{
    int sum=0;
    while(n>0)
    {
        sum=sum*10+n%10;
        n/=10;
    }
    return sum;
}
int is_prime(int n)
{
    int i,k;
    if(n==1)
        return 0;
    k=sqrt(n);
    for(i=2;i<=k;i++)
        if(n%i==0)
            return 0;
    return 1;
}
int main()
{
       int n,i,ans=0;
 
    scanf("%d",&n);
    for(i=11;i<=n;i++)
    {
        if(is_prime(i) && palindrome(i)==i)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}