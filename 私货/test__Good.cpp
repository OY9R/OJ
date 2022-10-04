#include<bits/stdc++.h>
using namespace std;
int main() {
	int _;
	cin>>_;
	while(_--){
		int hp,atk,n,h,a,t;
		cin>>hp>>atk>>n>>h>>a>>t;
		int hh=h;
		while(t--&&n&&hp>0){
			hp-=a*n;
			hh-=atk;
			if(hh<=0){
				hh=h;
				n--;
			}
		}
		if(hp>0)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}