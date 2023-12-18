#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<string> g;
// vector<vector<bool>> vis;
pair<int,int> way[4]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int x,int y,int step){
    // cout<<x<<y<<' ';
    g[x][y]='.';
    if(x==n-1&&y==m-1){
        cout<<"Yes";
        exit(0);
    }
    for(int i=0;i<4;i++){
        int nx=x+way[i].first;
        int ny=y+way[i].second;
        if(nx>=0&&ny>=0&&nx<n&&ny<m&&g[nx][ny]=="nukes"[(step+1)%5]){
            dfs(nx,ny,step+1);
        }
    }
    // g[x][y]="nukes"[step%5];
}
int main(){
    cin>>n>>m;
    g.resize(n);
//     vis = vector<vector<bool>>(n,vector<bool>(m));
    for(int i=0;i<n;i++)
        cin>>g[i];
//     for(int i=0;i<n;i++)
//         for(int j=0;j<m;j++)
//             vis[i][j]=1;
    string s="nukes";
    dfs(0,0,4);
    cout<<"No"<<endl;
}