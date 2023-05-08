// #include<bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define all(x) (x).begin(),(x).end()
// #define rep(i,a,n) for (int i=a;i<n;i++)
// #define per(i,a,n) for (int i=n-1;i>=a;i--)
// #define pb push_back
// #define mp make_pair
// #define fi first
// #define se second
// typedef vector<int> VI;
// typedef vector<long long> VL;
// typedef pair<int,int> PII;
// typedef long long ll;
// const int INF=0x3f3f3f3f,mod=1e9+7;
// const ll p10[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
// void solve(){
//     ll n,m,a,b;cin>>n>>m>>a>>b;
//     ll v=0;
//     for(ll i=b;i;i/=10)v+=p10[i%10];
//     for(ll i=a;i;i/=10)v-=p10[i%10];
//     for(ll i=(n/a+(n%a>0))*b;i<=m;i+=b){
//         ll v1=0,v2=0;
//         for(ll j=i/b*a;j;j/=10)v1+=p10[j%10];
//         for(ll j=i;j;j/=10)v2+=p10[j%10];
//         if(v2-v1==v){
//             bool flag=1;
//             if(a>9){
//                 ll aa=i/b*a,ta=a;
//                 for(;ta;ta/=10){
//                     for(ll t=ta%10;aa;aa/=10){
//                         if(t==aa%10)break;
//                     }
//                     if(aa){aa/=10;continue;}
//                     flag=0;break;
//                 }
//             }
//             if(flag&&b>9){
//                 ll bb=i,tb=b;
//                 for(;tb;tb/=10){
//                     for(ll t=tb%10;bb;bb/=10){
//                         if(t==bb%10)break;
//                     }
//                     if(bb){bb/=10;continue;}
//                     flag=0;break;
//                 }
//             }
//             if(flag)
//                 cout<<i/b*a<<' '<<i<<endl;
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);cout.tie(0);
//     solve();
//     return 0;
// }
#include <iostream>
using namespace std;
const int p10[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int n,m,a,b;
bool check(int x) {
    int nn=a*x,nm=b*x,ans=0;
    for(int ta=a,a1=ta%10;ta;ta/=10,a1=ta%10){
        int n1=nn%10;nn/=10;
        for(;n1!=a1;ans+=p10[n1],n1=nn%10,nn/=10)
            if(!nn)return 0;
    }
    for(;nn;nn/=10)ans+=p10[nn%10];
    for(int tb=b,b1=tb%10;tb;tb/=10,b1=tb%10){
        int m1=nm%10;nm/=10;
        for(;m1!=b1;ans-=p10[m1],m1=nm%10,nm/=10)
            if(!nm)return 0;
    }
    for(;nm;nm/=10)ans-=p10[nm%10];
    return !ans;
}
int main(){
    cin>>n>>m>>a>>b;
    for(int i=n/a+(n%a>0);i*b<=m;i++)
        if(check(i))cout<<i*a<<' '<<i*b<<'\n';
    return 0;
}