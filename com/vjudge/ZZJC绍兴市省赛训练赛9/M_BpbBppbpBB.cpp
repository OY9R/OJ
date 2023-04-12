#include<bits/stdc++.h>
using namespace std;
char g[1002][1002];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            if(g[i][j]=='#')sum++;
        }
    int hole=0;
    for(int i=4;i<=n-6;i++)
        for(int j=4;j<=m-6;j++)
            if(g[i][j]=='#'&&g[i][j+1]=='.'&&g[i][j+2]=='.'&&g[i][j+3]=='#'&&
               g[i+1][j-1]=='#'&&g[i+1][j]=='.'&&g[i+1][j+1]=='.'&&g[i+1][j+2]=='.'&&g[i+1][j+3]=='.'&&g[i+1][j+4]=='#'&&
               g[i+2][j-1]=='#'&&g[i+2][j]=='.'&&g[i+2][j+1]=='.'&&g[i+2][j+2]=='.'&&g[i+2][j+3]=='.'&&g[i+2][j+4]=='#'&&
               g[i+3][j]=='#'&&g[i+3][j+1]=='.'&&g[i+3][j+2]=='.'&&g[i+3][j+3]=='#')hole++;
    cout<<(100*hole-sum)/54<<' '<<hole-(100*hole-sum)/54*2<<endl;
    // cout<<sum<<' '<<hole;
}