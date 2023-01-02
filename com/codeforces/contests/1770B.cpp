#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
vector<int> a;
int n,m;
void solve(){
    cin>>n>>m;
    a.resize(n);
    if(n%2){
        a[n/2]=n/2+(n/2%2==0);
        for(int i=0;i<n/2;i++)
            if(i%2==0)a[i]=n-i;
            else a[i]=n+1-a[i-1];
        for(int i=n-1;i>n/2;i--)
            if(i%2==0)a[i]=i;
            else a[i]=n+1-a[i+1];
    }else{
        for(int i=0;i<n;i+=2)
            a[i]=n-i;
        for(int i=0;i<n;i+=2)
            a[n-i-1]=n-i-1;
    }
    for(int i=0;i<n;i++)cout<<a[i]<<' ';
    cout<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)
        solve();
    return 0;
}