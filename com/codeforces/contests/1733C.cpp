#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int m[N];
int o[2][N];
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>m[i];
		int odd=m[0]%2;
		int ans=0;
		for(int i=1;i<n;i++)
			if(m[i]%2!=odd){
				m[i]=m[i-1];
				o[0][ans]=i;
				o[1][ans]=i+1;
				ans++;
			}
		for(int i=n-2;i>=0;i--)
			if(m[i+1]<m[i]){
				m[i]=m[i+1];
				o[0][ans]=i+1;
				o[1][ans]=i+2;
				ans++;
			}
		cout<<ans<<endl;
		// for(int i=0;i<n;i++)
		// 	cout<<m[i]<<' ';
		// cout<<endl;
		for(int i=0;i<ans;i++)
			cout<<o[0][i]<<' '<<o[1][i]<<endl;
	}
	return 0;
}