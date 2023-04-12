#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(int t){
    ll n,m,x=0,y=0;cin>>n>>m;
    while(n>1||m>1){
        if(n==1){y += m-1; break;}
	    if(m==1){x += n-1; break;}
        int multi;
	    if(n>m) multi = n/m,x += multi,n -= multi*m;
	    else multi = m/n,y += multi,m -= multi*n;
    }
    cout<<"Scenario #"<<t<<":\n";
    cout<<x<<' '<<y<<"\n\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)solve(i);
    return 0;
}