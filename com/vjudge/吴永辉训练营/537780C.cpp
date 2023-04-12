#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
const int N=114514,M=1919810;
int h[N],e[N],ne[N],idx;
void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx++;}
void add2(int a,int b){add(a,b),add(b,a);}
void init(){
    memset(h,-1,sizeof h);
    add2(4,5);
    add2(3,5),add2(3,4);
    add2(2,5),add2(2,3);
    add2(1,5),add2(1,3),add2(1,2);
}
bool st[6][6];
vector<int> path;
void dfs(int u,int t){
    path.push_back(u);
    if(t==8){
        for(int i=0;i<=t;i++)
            cout<<path[i];
        cout<<endl;
        path.pop_back();
        return;
    }
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[u][j]){
            st[u][j]=st[j][u]=true;
            dfs(j,t+1);
            st[u][j]=st[j][u]=false;
        }
    }
    path.pop_back();
}
void solve(){
    init();
    dfs(1,0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}