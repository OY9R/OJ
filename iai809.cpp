#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdio>
using namespace std;
const int maxn=300001;
struct node
{
    int u,v;
    int nxt;
}edge[maxn*2];// 无向边，领接表开两倍 
int deep[maxn],ch[maxn],head[maxn],a[maxn];
int f[maxn][30];//倍增数组，f[i][j]表示i向上跳2^j到达的点 
int n,num=1;
inline void read(int &x)//读入优化 
{
    char c=getchar();
    x=0;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9')
    {
        x=x*10+c-48;
        c=getchar();
    }
}
void add_edge(int x,int y)//邻接表加边 
{
    edge[num].u=x;
    edge[num].v=y;
    edge[num].nxt=head[x];
    head[x]=num;
    num++;
}
void build(int r)//建树 
{
    for(int i=head[r];i!=-1;i=edge[i].nxt)
    {
        int xx=edge[i].v;
        if(deep[xx]==0)//如果点xx没有被访问过的话
        {
            deep[xx]=deep[r]+1;
            f[xx][0]=r;
            build(xx);//继续以xx为根建树 
        }
    }
}
void fill()
{
    for(int i=1;i<=29;i++)
    for(int j=1;j<=n;j++)
    f[j][i]=f[f[j][i-1]][i-1];//第j个节点，向上跳i能到达的节点先跳到2^(i-1)处再向上跳2^(i-1)能到达的节点
}
int lca(int x,int y)
{
    if(deep[x]<deep[y]) swap(x,y);//如果x在y上面，交换让x往上跳 
    for(int i=29;i>=0;i--)
    if(deep[f[x][i]]>=deep[y])
      x=f[x][i];//使x跳到与y同一深度 
    if(x==y) return x;
    for(int i=29;i>=0;i--)
    if(f[x][i]!=f[y][i])
    {
        x=f[x][i];
        y=f[y][i];
    }
    return f[x][0];//再跳一步，找到lca 
}
void dfs(int r)
{
    for(int i=head[r];i!=-1;i=edge[i].nxt)
    {
        int xx=edge[i].v;
        if(xx==f[r][0]) continue;
        dfs(xx);
        ch[r]+=ch[xx];//求子树和 
    }
}
inline void write(int x)//闲的没事干加的输出优化 
{
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
int main()
{
    int m;
    read(n);read(m);
    for(int i=1;i<=n;i++)
    {
        head[i]=-1;
    }
    int xx,yy;
    for(int i=1;i<=n-1;i++)
    {
        read(xx);
        read(yy);
        add_edge(xx,yy);
        add_edge(yy,xx);
    }
    deep[1]=1;
    build(1);//以1为根建树 
    fill();
    for(int i=1;i<=m;i++)
    {
        read(xx);
        read(yy);
        ch[xx]++;
        ch[yy]++;
        ch[lca(xx,yy)]--;
        ch[f[lca(xx,yy)][0]]--;
    }
    dfs(1);
    for(int i=2;i<=n;i++)
        ch[a[i]]--;//因为我们把既作为起点又做为终点的点算了两次，现在把这些点的权值减一即可 
    for(int i=1;i<=n;i++)
    {
        write(ch[i]);
        putchar(' ');//char(10)即换行 
    }
    return 0;
}