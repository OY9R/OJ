#include "bits/stdc++.h"
using namespace std;
#define ll unsigned long long
#define MAXN 1000001
string name;
ll n,m,ans;

int main() {
	cin>>n;
	while(n--){
		cin>>m;
		ans+=m;
	}
	cout<<ans<<endl;
	return 0;
}
