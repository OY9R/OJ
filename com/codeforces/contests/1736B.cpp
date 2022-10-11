#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
void solve(){
	int n,tmp;
	cin>>n;
	vector<int>a;
	for(int i=0;i<n;i++){
		cin>>tmp;
		a.push_back(tmp);
	}
	for(int i=2;i<n;i++){
		if(a[i-1]%gcd(a[i-2],a[i])){
			cout<<"no"<<endl;
			return;
		}
	}
	cout<<"yes"<<endl;
}
int main(){
	int _;
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}