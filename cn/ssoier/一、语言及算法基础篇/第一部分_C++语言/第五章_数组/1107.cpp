#include<bits/stdc++.h>
using namespace std;
int a[10001],b,c,d,e,sum;
int main(){
	cin>>b>>c;
	for(int i=0;i<=b;i++)
		a[i]=1;
	for(int i=1;i<=c;i++)
	{
		cin>>d>>e;
		for(int j=d;j<=e;j++)
			a[j]=0;
	}
	for(int i=0;i<=b;i++)
	 	if(a[i]==1)
			sum++;
	cout<<sum;
	return 0;	
}