#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int maxn=0,g;cin>>g;
        while(--n){
            int in;cin>>in;
            g=__gcd(g,in);
            maxn=max(maxn,in);
        }
        cout<<maxn/g<<'\n';
    }
}