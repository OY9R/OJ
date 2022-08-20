#include <stdio.h>
#define N 201
double temperature[N];
int cough[N];
char name[N][N];
int judge(double x,int y)
{
    if((x>=37.5)&&(y==1))
        return 1;
    else
        return 0;
}
int main()
{
    int n,sum=0,i;
 
	scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%s %lf %d",&name[i],&temperature[i],&cough[i]);
    for(i=1;i<=n;i++)
    {
        if(judge(temperature[i],cough[i]))
        {
            printf("%s\n",name[i]);
		    sum++;
        }
    }
    printf("%d\n",sum);
	return 0;
}