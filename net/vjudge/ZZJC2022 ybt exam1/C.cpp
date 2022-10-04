#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	cin>>_;
	while(_--) {
		ll hp,atk,n,h,a,t;
		cin>>hp>>atk>>n>>h>>a>>t;
		// hp-=t*a*n;
		// ll tt=h/atk+(h%atk>0);
		// t-=tt;
		// while(hp<=0&&t>0)hp+=t*a,t-=tt;
		int hh=h;
		while(t--&&n&&hp>0){
			hp-=a*n;
			hh-=atk;
			if(hh<=0){
				hh=h;
				n--;
			}
		}
		if(hp>0)cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}