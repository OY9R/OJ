#include<bits/stdc++.h>
using namespace std;
int a,c,sum=0,b[108];
int main(){
	cin>>a;	
	for(int i=1;i<=a;i++)
		cin>>b[i];     	
	cin>>c;
	for(int i=1;i<=a;i++)
		if(b[i]==c)
			sum++;
	cout<<sum;
	return 0;
}