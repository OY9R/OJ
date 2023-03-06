#include<bits/stdc++.h>
using namespace std;
const int N = 5000;
int p[N][N];
int node[N*N];
int build(int k,int lx,int ly,int rx,int ry){
    if(lx==rx&&ly==ry)
        return node[k]=(1<<p[lx][ly]);
    int mx=(lx+rx)/2,my=(ly+ry)/2;
    int v=0;
    v|=build(k*4,lx,ly,mx,my);
    v|=build(k*4+1,lx,my+1,mx,ry);
    v|=build(k*4+2,mx+1,ly,rx,my);
    v|=build(k*4+3,mx+1,my+1,rx,ry);
    return node[k]=v;
}
void dfs(int u){
    if(node[u]==3){
        if(u>1)putchar('*');
        dfs(4*u);
        dfs(4*u+1);
        dfs(4*u+2);
        dfs(4*u+3);
    }else{
        if(node[u]==2)putchar('1');
        else putchar('0');
    }
}
int main(){
    int n,lx,ly,rx,ry,m;
    char str[114514];
    scanf("%d",&m);
    getchar();
    while(m--){
        gets(str);
        stringstream sin(str);
        string s;
        sin>>n;
        if(__builtin_popcount(n)!=1||n<=1){
            puts("Size is invalid");
            continue;
        }
        memset(p,0,sizeof(p));
        while(sin>>s){
            sscanf(s.c_str(),"(%d,%d)",&lx,&ly);
            if(sin>>s){
                sscanf(s.c_str(),"(%d,%d)",&rx,&ry);
                lx--,ly--,rx--,ry--;
                for(int i=lx;i<=rx;i++)
                    for(int j=ly;j<=ry;j++)
                        p[j][i]=1;
            }
        }
        build(1,0,0,n-1,n-1);
        dfs(1);
        puts("");
    }
    return 0;
}