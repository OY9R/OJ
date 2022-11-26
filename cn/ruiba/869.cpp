#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    while(cin>>n)
        cout<<(n--*n>>1)<<'\n';
    return 0;
}