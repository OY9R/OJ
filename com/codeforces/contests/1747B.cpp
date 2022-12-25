#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
        cout<<n/2+n%2<<'\n';
        for(int i=1;i<=n*3/2;i+=3){
            cout<<i<<' '<<n*3-i+1<<'\n';
        }
	}
	return 0;
}