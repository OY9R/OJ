#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int main() {
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==abs(b-c)+c){
			cout<<3<<endl;
		}else if(a<abs(b-c)+c){
			cout<<1<<endl;
		}else{
			cout<<2<<endl;
		}
	}
	return 0;
}
