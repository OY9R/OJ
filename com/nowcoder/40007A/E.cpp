#include "bits/stdc++.h"
#define ll long long
using namespace std;
int m[100004];
int gcd(int a,int b){
	if(a*b)
		return a?gcd(b,a%b):b;
	else
		return max(a,b);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,g;
	bool all1=true;
	bool all0=true;
	cin>>n>>m[0];
	g=m[0];
	all1=g<=1;
	all0=g==0;
	for(int i=1;i<n;i++){
		cin>>m[i];
		all1=all1&&m[i]<=1;
		all0=all0&&m[i]==0;
		if(g!=1)g=gcd(g,m[i]);
		//cout<<g;
	}
	if(all0) cout<<0<<endl;
	else if(g!=1||all1)cout<<1<<endl;
	else cout<<2<<endl;
	return 0;
}
