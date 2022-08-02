#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n,m,x,y,a,b,t;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>m>>n;
	int ans=0;
	for (int i = m; i <= n; ++i){
		if (i%17==0)
		{
			ans+=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
