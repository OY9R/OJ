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
const int N=114514,M=1919810;
int n1,n2;
int h[N],e[M],ne[M],idx;
int match[N];
bool st[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void init(){
    idx=0;
    memset(h,-1,sizeof h);
}
bool find(int x){
    for(int i=h[x];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j]){
            st[j]=true;
            if(match[j]==0||find(match[j])){
                match[j]=x;
                return true;
            }
        }
    }
    return false;
}
void solve(){
    init();
    int n,m,k,ans=0;cin>>n>>m>>k;
    while(k--){
        int a,b;cin>>a>>b;
        add(a,b);
    }
    int res=0;
    memset(match,0,sizeof match);
    for(int i=1;i<=n;i++){
        memset(st,false,sizeof st);
        if(find(i))res++;
    }
    cout<<n+m-res<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}