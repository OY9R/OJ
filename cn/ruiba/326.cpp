#include "bits/stdc++.h"
using namespace std;
int m,n,x;
char mn[7][7];
void dfs(int i,int j, int s){
    //cout<<i<<' '<<j<<endl;
    if(mn[i][j]=='D'){
        cout<<"YES";
        exit(0);
    }
    if(s!=x){
        mn[i][j]='+';
        if(i<m&&(mn[i+1][j]=='.'||mn[i+1][j]=='D'))dfs(i+1,j,s+1);
        if(j<n&&(mn[i][j+1]=='.'||mn[i][j+1]=='D'))dfs(i,j+1,s+1);
        if(i>1&&(mn[i-1][j]=='.'||mn[i-1][j]=='D'))dfs(i-1,j,s+1);
        if(j>1&&(mn[i][j-1]=='.'||mn[i][j-1]=='D'))dfs(i,j-1,s+1);
        mn[i][j]='.';
    }
}
int main(){
    cin>>m>>n>>x;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            cin>>mn[i][j];

    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            if(mn[i][j]=='S'){
                dfs(i,j,0);
            }
    cout<<"NO";
    return 0;
}
