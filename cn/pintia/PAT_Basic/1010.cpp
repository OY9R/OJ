#include "bits/stdc++.h"
using namespace std;
int a[100005];
int main(){
	int x,n;
	bool flag=true;
	while(cin>>x>>n){
		if(n){
			if(!flag)cout<<' ';
			cout<<x*n<<' '<<(n-1);
			flag=false;
		}
	}
	if(flag)cout<<"0 0";
	return 0;
}
