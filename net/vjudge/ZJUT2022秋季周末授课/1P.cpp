#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+9;
int main() {
	ll a,b;
	cin>>a>>b;
	if(a>b||a%2!=b%2)
		cout<<-1<<endl;
	else if(a==b&&a!=0)
		cout<<1<<endl<<a<<endl;
	else if(a==0&&b==0)
		cout<<0<<endl;
	else{
		ll x=(b-a)>>1;
		if(x&a)
			cout<<"3\n"<<a<<' '<<x<<' '<<x<<endl;
		else
			cout<<"2\n"<<(a^x)<<' '<<x<<endl;
	}
	return 0;
}