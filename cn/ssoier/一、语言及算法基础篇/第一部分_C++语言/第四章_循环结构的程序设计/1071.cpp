#include <stdio.h>
long long feibonaqie(int n)
{
   long long int f[46];
   f[0]=1;f[1]=1;
   if(n<=2)
    {
      return 1;
     }
     else
     {
       for(int i=2;i<n+1;i++)
        {
             f[i]=f[i-1]+f[i-2];
       }
     }
  
   return f[n-1];
}
int main ()
{
  int k;
  scanf("%d",&k);
  printf("%lld",feibonaqie(k));
  return 0;
}