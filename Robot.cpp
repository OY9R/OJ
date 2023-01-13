#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N=55,M=55;
bool a[N][M],b[N][M],st[N][M][4];
PII fs[4]={make_pair(0,1),make_pair(-1,0),make_pair(0,-1),make_pair(1,0)};
int n,m,sx,sy,ex,ey,sf;
struct Robot{int x,y,f,t;};
int bfs(){
    memset(st,0,sizeof st);
    Robot start;start.x=sx,start.y=sy,start.f=sf,start.t=0;
    queue<Robot> q;q.push(start);
    st[sx][sy][sf]=true;
    while(q.size()){
        Robot u=q.front();q.pop();
        //cout<<u.x<<' '<<u.y<<' '<<u.f<<' '<<u.t<<endl;
        if(u.x==ex&&u.y==ey)return u.t;
        u.t++;
        int nx=u.x,ny=u.y,nf=u.f,tt=1;
        u.x+=fs[u.f].first,u.y+=fs[u.f].second;
        for(;tt<=3&&u.x>0&&u.x<=n&&u.y>0&&u.y<=m&&!b[u.x][u.y];
            u.x+=fs[u.f].first,u.y+=fs[u.f].second,tt++)
            if(!st[u.x][u.y][u.f]) //必须放里面
                st[u.x][u.y][u.f]=true,
                q.push(u);
        u.x=nx,u.y=ny;
        if(!st[u.x][u.y][(u.f+1)%4])
            st[u.x][u.y][(u.f+1)%4]=true,
            u.f=(u.f+1)%4,
            q.push(u);
        u.f=nf;
        if(!st[u.x][u.y][(u.f+3)%4])
            st[u.x][u.y][(u.f+3)%4]=true,
            u.f=(u.f+3)%4,
            q.push(u);
    }
    return -1;
}
void solve(){
    cin>>n>>m;
    if(n--+m--==0)exit(0);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            cin>>a[i][j],b[i][j]=a[i][j]||a[i-1][j]||a[i][j-1]||a[i-1][j-1];
    string s;cin>>sx>>sy>>ex>>ey>>s;
    sf=(s[0]>'e')+(s[0]>'n')+(s[0]=='s');
    cout<<bfs()<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(true)solve();
    return 0;
}