#include<bits/stdc++.h>
using namespace std;
int a[101],b;
int main(){
	cin>>b;
	for(int i=1;i<=b;i++)
		cin>>a[i];
	for(int i=b;i>=1;i--)
		cout<<a[i]<<" ";
	return 0; 
}