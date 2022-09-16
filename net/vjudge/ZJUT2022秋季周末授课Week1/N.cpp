#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100001;
const int MOD=1e9+7;
int main() {
	int n,m;
	ll a,x=0,y=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		x=(x+((i<<1)-n-1)*a)%MOD;
	}
	for(int i=1;i<=m;i++){
		cin>>a;
		y=(y+((i<<1)-m-1)*a)%MOD;
	}
	cout<<x*y%MOD<<endl;
	return 0;
}