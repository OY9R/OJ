#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define N 10005
int a[N],b[N],g[N],k[N];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>g[i]>>k[i];
	}
	int x,y;
	cin>>x>>y;
	for(int i=n;i>=1;i--)
	{
		if(x>=a[i]&&x<=a[i]+g[i]&&y>=b[i]&&y<=b[i]+k[i])
		{
			cout<<i; return 0;
		}
	}
	return 0;
}