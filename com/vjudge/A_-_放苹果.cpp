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
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
int dfs(int m,int n){
    if(m==0||n==1)return 1;
    if(m<n)return dfs(m,m);
    return dfs(m,n-1)+dfs(m-n,n);
}
void solve(){
    int n,m;cin>>n>>m;
    cout<<dfs(n,m)<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}