#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    while(q--){
        int x,y,k;
        cin>>x>>y>>k;
        int l=1,r=1,c=1;
        int t=min(x?(n-1)/x+1:INT_MAX,y?(m-1)/y+1:INT_MAX);
        //cout<<t<<' ';
        l+=k/t;
        k%=t;
        r+=k*x;
        c+=k*y;
        cout<<l<<' '<<r<<' '<<c<<'\n';
    }
    return 0;
}