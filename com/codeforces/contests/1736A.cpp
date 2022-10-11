#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	vector<int>a,b;
	int a1=0,b1=0,diff=0,tmp;
	for(int i=0;i<n;i++){
		cin>>tmp;
		a.push_back(tmp);
		a1+=a[i];
	}
	for(int i=0;i<n;i++){
		cin>>tmp;
		b.push_back(tmp);
		b1+=b[i];
		if(a[i]!=b[i])diff++;
	}
	cout<<min(1+abs(a1-b1),diff)<<endl;
}
int main(){
	int _;
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}