#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int x,n;
	double s=1;
	scanf("%d%d",&x,&n);
	s= x;
	for(int i=0;i<n;i++)
	{
		s=s+s*0.001;
	}
	printf("%.4lf",s);
	return 0;
}