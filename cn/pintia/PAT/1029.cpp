#include "bits/stdc++.h"
using namespace std;
int flag[156];
int main()
{
	string a,b;
	cin>>a>>b;
	for(int i=0;i<b.length();i++)
	{
		while(a.find(b[i])!=-1)
			a.erase(a.find(b[i]),1);
	}
	for(int i=0;i<a.length();i++)
	{
		if(flag[a[i]-'0']!=1)
		{
			flag[a[i]-'0']=1;
			if(a[i]>='a'&&a[i]<='z')
			{
				flag[a[i]-'0'-32]=1;
				printf("%c",a[i]-32);
			}
			else if(a[i]>='A'&&a[i]<='Z')
			{
				flag[a[i]-'0'+32]=1;
				printf("%c",a[i]);
			}	
			else
				printf("%c",a[i]);
		}
	}
	return 0;
} 

