#include"bits/stdc++.h"
using namespace std;
bool check(int a, int b){
	int t=1,tmp=a;
	while(a>0){
		t*=10;
		a/=10;
	}
	return tmp==b%t;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int t,f=0;
		cin>>t;
		for(int i=1;i<=9;i++)
			if(check(t,i*t*t)){
				f=1;
				cout<<i<<' '<<i*t*t<<endl;
				break;
			}
		if(!f)
			cout<<"No"<<endl;
	}
	return 0;
}