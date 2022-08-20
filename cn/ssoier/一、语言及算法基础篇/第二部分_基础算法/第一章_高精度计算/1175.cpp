#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a[301]={},b[301]={2,3,1},c[301]={};
void init(int x[])
{
	string s;
	cin>>s;
	x[0]=s.length(); 
	for(int i=1;i<=x[0];i++) x[i]=s[x[0]-i]-48;
}
void print(int a[])
{
	if(a[0]==0)
	{
		cout<<0<<endl;
		return;	
	}
	for(int i=a[0];i>0;i--) cout<<a[i];
	cout<<endl;
	return;
} 
int compare(int a[],int b[])
{
	if(a[0]<b[0]) return -1;
	if(a[0]>b[0]) return 1;
	for(int i=a[0];i>0;i--)
	{
		if(a[i]>b[i]) return 1;
		if(a[i]<b[i]) return -1;
	}
	return 0;
}
void jian(int a[],int b[])
{
	int flag;
	flag=compare(a,b);
	if(flag==0)
	{
		a[0]=0;
		return;
	}
	if(flag==1)
	{
		for(int i=1;i<=a[0];i++)
		{
			if(a[i]<b[i])
			{
				a[i+1]--;
				a[i]+=10;
			}
			a[i]-=b[i]; 
		}
		while(a[a[0]]==0&&a[0]>0) a[0]--;
		return;
	}
}
void numcpy(int p[],int q[],int det)
{
	for(int i=1;i<=p[0];i++) q[i+det-1]=p[i];
	q[0]=p[0]+det-1; 
}
void chu(int a[],int b[],int c[])
{
	int t[301];
	c[0]=a[0]-b[0]+1;
	for(int i=c[0];i>0;i--)
	{
		memset(t,0,sizeof(t));
		numcpy(b,t,i);
		while(compare(a,t)>=0)
		{
			c[i]++;
			jian(a,t);
		} 
	}
	while(c[c[0]]==0&&c[0]>0) c[0]--;
	return;
}
int main()
{
	init(a);
	chu(a,b,c);
	print(c);
	print(a);
	return 0;
}