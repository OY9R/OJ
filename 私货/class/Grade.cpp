#include<bits/stdc++.h>
using namespace std;
const int N = 100100;
int h[N], e[N], ne[N], idx;
char cc[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
bool st[N];
void DFS(int u){
    st[u]=true;
    printf("%d%c ",u,cc[u]);
    for(int i=h[u];i!=-1;i=ne[i])
        if(!st[e[i]])DFS(e[i]);
}
void BFS(int u){
    queue<int> q;q.push(u);
    st[u]=true; printf("%d%c ",u,cc[u]);
    while(q.size()){
        int t=q.front();q.pop();
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(!st[j]){
                st[j]=true;
                printf("%d%c ",j,cc[j]);
                q.push(j);
            }
        }
    }  
}
void build()c
    memset(h,-1,sizeof h);idx=0;
    printf("图的类型 (0: 有向图 1: 无向图): ");int o;cin>>o;
    printf("图的点数: ");int n;cin>>n;
    printf("点的名称 (一行输入一个字符:c)\n");
    for(int i=0;i<n;i++){
        printf("点%d:",i);cin>>cc[i];
    }
    printf("图的边数: ");int m;cin>>m;
    printf("由边连接的两点 (一行两个整数:1 2)\n");
    for(int i=1;i<=m;i++){
        printf("边%d:",i);int a,b;cin>>a>>b;
        add(a,b);if(o)add(b,a);
    }
    printf("图的邻接表为:\n");
    for(int i=0;i<n;i++){
        printf("(%d%c)",i,cc[i]);
        for(int j=h[i];j!=-1;j=ne[j])printf("->%d%c",e[j],cc[e[j]]);
        printf("\n");
    }
}
void menu() {
    int t;
    while(true){
        printf("《图子系统》(1: 更新 2: 深优 3: 广优 0: 退出): ");
        int o;cin>>o;
        switch(o){
        case 1:build();break;
        case 2:memset(st,0,sizeof st);
            printf("起始点: ");cin>>t;
            DFS(t);cout<<endl;break;
        case 3:memset(st,0,sizeof st);
            printf("起始点: ");cin>>t;
            BFS(t);cout<<endl;break;
        default:exit(0);
        }
    }
}
int main() {
    menu();
    return 0;
}