#include<bits/stdc++.h>
using namespace std;
int n,m,t,sx,sy,fx,fy,t1,t2,tot=0,change[5][3]={{0,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
bool ditu[6][6]={false};
void dfs(int x,int y) {
    if(x>=1 && y>=1 && x<=m && y<=n && ditu[x][y]==false)
        if(x==fx&&y==fy)
            tot++;
        else for(int i=1; i<=4; i++) {
            ditu[x][y]=true;
            dfs(x+change[i][1],y+change[i][2]);
            ditu[x][y]=false;
        }
}
int main() {
    scanf("%d%d%d%d%d%d%d",&n,&m,&t,&sx,&sy,&fx,&fy);
    for(int i=1; i<=t; i++) {
        scanf("%d%d",&t1,&t2);
        ditu[t1][t2]=true;
    }
    dfs(sx,sy);
    printf("%d",tot);
    return 0;
}
