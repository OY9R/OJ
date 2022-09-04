#include "bits/stdc++.h"
#define ll long long
using namespace std;
int m[10004];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>m[i];
	sort(m+1,m+n+1);
	double ans=(m[1]+m[2])/2.0;
	for(int i=3;i<=n;i++){
		if((ans+m[i])/2>ans)
			ans=(ans+m[i])/2;
	}
	cout<<floor(ans)<<endl;
	return 0;
}
