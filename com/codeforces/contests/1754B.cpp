#include<bits/stdc++.h>
using namespace std;
void solve(int n){
	for(int i=n/2;i>0;i--){
		cout<<i<<' '<<i+n/2<<' ';
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%2==0){
			solve(n);
		}else{
			cout<<n<<' ';
			solve(n-1);
		}
		cout<<endl;
	}
	return 0;
}