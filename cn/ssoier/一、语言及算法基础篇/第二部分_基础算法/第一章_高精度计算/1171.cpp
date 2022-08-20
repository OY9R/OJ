#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	char c[31];
	int x,len,flag=0;
	scanf("%s",c);
	len=strlen(c);
	for(int k=2;k<=9;k++)
	{
		x=0;
		for(int j=0;j<len;j++)
		{
			x=x*10+(c[j]-'0');
			x%=k;
		}
		if(x==0)
		{
			flag=1;
			cout<<k<<" ";
		}
	}
	if(!flag) cout<<"none";
	return 0;
}