#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll in,ans;
	cin>>ans;
	while(cin>>in)
		ans^=in;
	cout<<ans<<endl;
	return 0;
}