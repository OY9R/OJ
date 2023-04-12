// https://vjudge.net/contest/538064#problem/F
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
#define F first
#define S second
struct status{
    int n,s,t;
    bool operator<(const status o)const{
        if(n!=o.n)return n<o.n;
        if(s!=o.s)return s<o.s;
        return t<o.t;
    }
};
const int N=11,M=1<<(N-1);
int G[N],R[N],r,d,s,tt;
bool st[N][M];
map<status,status> path;
void print(status u){
    if(u.t==0)return;
    print(path[u]);
    if(path[u].n!=u.n) cout<<"- Move to room "<<u.n<<".\n";
    else cout<<"- Switch "<<(u.s&(u.s^path[u].s)?"on":"off")<<" light in room "<<log2(path[u].s^u.s)+1<<".\n";
}
status bfs(){
    queue<status> q;
    status tmp={1,1,0};
    q.push(tmp);
    st[1][1]=true;
    while(q.size()){
        status u=q.front();q.pop();
        //cout<<u.n<<' '<<u.s<<' '<<u.t<<endl;
        if(u.n==r&&u.s==1<<(r-1))return u;
        int g=G[u.n];
        while(g>0){
            int to=(int)log2(g&-g)+1;
            if(!st[to][u.s]&&(u.s&(g&-g))!=0){
                st[to][u.s]=true;
                status tmp={to,u.s,u.t+1};
                q.push(tmp);
                path[tmp]=u;
            }g^=g&-g;
        }
        int r=R[u.n];
        while(r>0){
            if(!st[u.n][u.s^(r&-r)]){
                st[u.n][u.s^(r&-r)]=true;
                status tmp={u.n,u.s^(r&-r),u.t+1};
                q.push(tmp);
                path[tmp]=u;
            }r^=r&-r;
        }
    }
    status ret={0,0,-1};
    return ret;
}
void solve(){
    cin>>r>>d>>s;
    if(r+d+s==0)exit(0);
    memset(G,0,sizeof G);
    memset(R,0,sizeof R);
    memset(st,0,sizeof st);
    path=map<status,status>();
    for(int i=1;i<=d;i++){
        int a,b;cin>>a>>b;
        G[a]|=1<<(b-1);
        G[b]|=1<<(a-1);
    }
    for(int i=1;i<=s;i++){
        int a,b;cin>>a>>b;
        if(a!=b)R[a]|=1<<(b-1);
    }
    status ans=bfs();
    cout<<"Villa #"<<++tt<<"\nThe problem can";
    if(ans.t==-1)cout<<"not be solved.\n\n";
    else{cout<<" be solved in "<<ans.t<<" steps:\n";print(ans);cout<<endl;}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(true)solve();
    return 0;
}