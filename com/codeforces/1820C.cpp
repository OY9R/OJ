#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int n,t,mex=0,x=-1,y=-1,z=0;cin>>n;
    vector<int> a(n),b(n+1);
    for(int i=0;i<n;i++){cin>>a[i];if(a[i]<=n)b[a[i]]++;}
    while(b[mex])mex++;
    for(int i=0;i<n;i++)if(a[i]==mex+1)x=~x?x:i,y=i;
    if(~x){
        vector<int> c(n+1);
        for(int i=x;i<=y;i++)a[i]=mex;
        for(int i=0;i<n;i++)if(a[i]<=n)c[a[i]]++;
        while(c[z])z++;
        cout<<(z==mex+1?"Yes":"No")<<endl;
    }else{
        bool flag=0;
        for(int i=0;i<n;i++)if(a[i]>mex)flag=1;
        for(int i=0;i<mex;i++)if(b[i]>=2)flag=1;
        cout<<(flag?"Yes":"No")<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--)solve();
    return 0;
}