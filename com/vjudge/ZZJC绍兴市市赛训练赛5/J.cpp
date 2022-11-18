#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    while(t--){
        int l,r;cin>>l>>r;
        if(l*2<=r){
            cout<<l<<' '<<l*2<<'\n';
        }else{
            cout<<"-1 -1\n";
        }
    }
}