#include<bits/stdc++.h>
using namespace std;
double sum=0,b[11];
double a[11]={0,28.9,32.7,45.6,78,35,86.2,27.8,43,56,65};
int main(){
	for(int i=1;i<=10;i++)
		cin>>b[i];     	
	for(int i=1;i<=10;i++)
		sum+=b[i]*a[i];
	cout<<fixed<<setprecision(1)<<sum;
	return 0;
}