#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll g=__gcd(a+b,b);
        cout<<(a+b)/g<<'/'<<b/g<<'\n';
    }
}