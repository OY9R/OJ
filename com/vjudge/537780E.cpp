#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
bool g[102][102];
int cnt=0;
void dfs(int x,int y){
    g[x][y]=false;
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            if((i||j)&&g[x+i][y+j])
                dfs(x+i,y+j);
}
void solve(){
    int xn,yn;cin>>xn>>yn;
    if(xn+yn==0)exit(0);
    cnt=0;
    for(int i=0;i<=xn+1;i++)
        g[i][yn+1]=0;
    for(int i=0;i<=yn+1;i++)
        g[xn+1][i]=0;
    for(int i=1;i<=xn;i++)
        for(int j=1;j<=yn;j++){
            char c;cin>>c;
            g[i][j]=c=='@';
        }
    for(int i=1;i<=xn;i++)
        for(int j=1;j<=yn;j++)
            if(g[i][j]){
                cnt++;
                dfs(i,j);
            }
    cout<<cnt<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(true)solve();
    return 0;
}