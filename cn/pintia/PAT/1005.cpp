#include "bits/stdc++.h"
using namespace std;
#define ll long long
int a[10005];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		m=max(m,t);
		a[t]++;
		if(a[t]!=1)continue;
		while(t!=1){
			if(t%2){
				t=(3*t+1)/2;
			}else{
				t/=2;
			}
			a[t]--;
		}
	}
	bool f=true;
	for(int i=m;i>0;i--){
		if(a[i]==1){
			if(f){
				f=false;
				cout<<i;
			}else{
				cout<<' '<<i;
			}
		}
	}
	return 0;
}

