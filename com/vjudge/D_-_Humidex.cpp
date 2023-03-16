#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
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
    double t,d,h;t=d=h=200;
    for(int i=0;i<2;i++){
        char a;cin>>a;
        switch(a){
            case 'E':exit(0);
            case 'T':cin>>t;break;
            case 'D':cin>>d;break;
            case 'H':cin>>h;
        }
    }
    if(h==200)
        h=t+0.5555*(6.11*exp(5417.7530*(1/273.16-1/(d+273.16)))-10);
    else if(t==200)
        t=h+0.5555*(6.11*exp(5417.7530*(1/273.16-1/(d+273.16)))-10);
    else if(d==200)
        d=1/(1/273.16-log(((h-t)/0.5555+10.0)/6.11)/5417.7530)-273.16;
    printf("T %.1f D %.1f H %.1f\n",t,d,h);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(true)solve();
    return 0;
}