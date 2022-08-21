#include "bits/stdc++.h"
using namespace std;
int a[100005];
int main(){
	int n,m;
	cin>>n>>m;
	m%=n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=n-m;i<n-m+n;i++){
		if(i==n-m)cout<<a[i%n];
		else cout<<' '<<a[i%n];
	}
	return 0;
} 
