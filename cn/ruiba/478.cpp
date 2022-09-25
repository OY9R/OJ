#include<bits/stdc++.h>
using namespace std;
const int N=10000100;
int m[100100];
int cnt[N];
int ans[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,mmax=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i];
		cnt[m[i]]++;
		mmax=mmax<m[i]?m[i]:mmax;
	}
	for(int i=1;i<=mmax;i++)
		if(cnt[i])
			for(int j=i;j<=mmax;j+=i)
				ans[j]+=cnt[i];
	for(int i=0;i<n;i++)
		cout<<ans[m[i]]-1<<endl;
	return 0;
}