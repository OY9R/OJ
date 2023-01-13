#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
const int N=1919810,M=114514;
int h[N],e[N],ne[N],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
bool st[N];
int dd=0,du=1;
void dfs(int u,int d){
    if(d>dd)dd=d,du=u;
    st[u]=true;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!st[j])dfs(j,d+1);
    }
}
void solve(){
    int n,i;cin>>n;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs(1,0);
    memset(st,0,sizeof st);
    dfs(du,0);
    for(i=0;(1<<i)<dd;i++);
    cout<<i;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    memset(h,-1,sizeof h);
    solve();
    return 0;
}