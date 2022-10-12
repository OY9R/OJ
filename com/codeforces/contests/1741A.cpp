#include "bits/stdc++.h"
using namespace std;
#define ll long long
int t, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		string a,b;
		cin>>a>>b;
		int an,bn;
		if(a=="M")an=0;
		else if(a[a.size()-1]=='S')an=a.size()*-1;
		else an=a.size();
		if(b=="M")bn=0;
		else if(b[b.size()-1]=='S')bn=b.size()*-1;
		else bn=b.size();
		if(an>bn){
			cout<<'>'<<endl;
		}else if(an==bn){
			cout<<'='<<endl;
		}else{
			cout<<'<'<<endl;
		}
	}
	return 0;
}
