#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
void solve(){
    int n;cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int f=0,s=0,c=0;
    for(int i=0;i<n;i++){
        if(a[i]!=i+1&&a[i]!=n-i)c++;
        else if(a[i]!=i+1)f++;
        else if(a[i]!=n-i)s++;
    }
    //cout<<f<<' '<<s<<' ';
    if(f+c<=s)cout<<"First";
    else if(s+c<f)cout<<"Second";
    else cout<<"Tie";
    cout<<endl;
}
int main() {
    int n;cin>>n;
    while(n--)
        solve();
    return 0;
}