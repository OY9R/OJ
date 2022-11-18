#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    while(t--){
        ll m,d,w;cin>>m>>d>>w;
        ll ans=0;
        ll n=min(m,d);
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(((j-i)*d)%w==(j-i)%w){
        //             //cout<<i<<' '<<j<<endl;
        //             ans++;
        //         }
        //     }
        // }
        // for(ll i=d-1,j=1;j<n;i+=d-1,j++){
        //     if(i>=w)i%=w;
        //     if(i==0){
        //         ans+=n-j;
        //     }
        // }
        ll jump=d-1;
        for(ll i=d-1,j=1;j<n;i+=jump,j++){
            if(i>=w)i%=w;
            if(i==0){
                if(jump==d-1)jump=(j-1)*jump;
                ans+=n-j;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}