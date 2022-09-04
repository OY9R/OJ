#include "bits/stdc++.h"
#define ll long long
using namespace std;
int m[100005];
int n,k,tmp;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>tmp;
		m[tmp]++;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		cin>>tmp;
		cout<<m[tmp];
		if(i==k-1)
			cout<<endl;
		else
			cout<<" ";
	}
	return 0;
 } 
