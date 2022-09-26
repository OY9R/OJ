#include "bits/stdc++.h"
#define ll long long
#define N 100009
using namespace std;
int a[N],b[N],m[N];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i];
		int k=n;
		for(int i=n;i>=1;i--){
			while(b[k-1]>=a[i]&&k>1)
				k--;
			m[i]=b[k]-a[i];
		}
		for(int i=1;i<=n;i++){
			cout<<m[i]<<' ';
		}
		cout<<endl;
		int kk;
		for(int i=n;i>=1;i--){
			int k=i;
			if(b[k]>=a[k+1]&&k<n)k=kk;
			else kk=k;
			m[i]=b[k]-a[i];
		}
		for(int i=1;i<=n;i++){
			cout<<m[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
