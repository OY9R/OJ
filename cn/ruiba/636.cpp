#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    ll a,b,c;
    while(cin>>a>>b>>c){
        ll t=a/gcd(a,b)*b;
        cout<<t/gcd(t,c)*c<<'\n';
    }
}