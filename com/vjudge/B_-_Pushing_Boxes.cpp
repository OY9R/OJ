#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
int n,m;
int map[23][23];
int t[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int g[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char c[4]={'s','n','e','w'};
char cx[4]={'N','S','W','E'};
string sch,tch;
int sn,tn,sx,sy,tx,ty,bx,by;
int sum[23][23],cas=0;
int tsum[4][23][23];
struct st{
	string ch;
	int n,x,y;
	friend bool operator < (const st &a,const st &b){return a.n>b.n;}
};
struct kpa{
	string ch;
	int n,x,y,f;
	friend bool operator < (const kpa &a,const kpa &b){return a.n>b.n;}
};

void sbfs(int sx,int sy,int lx,int ly){
	sn=-1;sch="";
	memset(sum,0xf,sizeof(sum));
	sum[sx][sy]=0;
	priority_queue <st> q;
	st tmp,tp;
	tmp.x=sx;tmp.y=sy;
	tmp.n=0;tmp.ch="";
	q.push(tmp);
	while(!q.empty()){
		tmp=q.top();q.pop();
		if(tmp.x==lx&&tmp.y==ly){
			sch=tmp.ch;
			sn=tmp.n;
			return;
		}
		if(tmp.n>sum[tmp.x][tmp.y]) continue;
		tp.n=tmp.n+1;
		for(int i=0;i<4;i++){
			tp.x=tmp.x+t[i][0];
			tp.y=tmp.y+t[i][1];
			if(map[tp.x][tp.y]&&tp.n<sum[tp.x][tp.y])
				sum[tp.x][tp.y]=tp.n,
				tp.ch=tmp.ch+c[i],
				q.push(tp);
		}
	}
}
void tbfs(){
	priority_queue <kpa> q;
	memset(tsum,0xf,sizeof(tsum));
	kpa tmp,tp;
	int x,y,f;
	tmp.x=bx;tmp.y=by;
	map[bx][by]=0;
	for(int i=0;i<4;i++)
		if(map[bx+t[i][0]][by+t[i][1]]){
			sbfs(sx,sy,bx+t[i][0],by+t[i][1]);
			if(sn!=-1)
				tmp.ch=sch,
				tmp.n=0,
				tmp.f=i,
				tsum[i][bx][by]=0,
				q.push(tmp);
		}
	map[bx][by]=1;
	while(!q.empty()){
		tmp=q.top();q.pop();
		x=tmp.x;y=tmp.y;f=tmp.f;
		if(x==tx&&y==ty){
			tn=tmp.n;
			tch=tmp.ch;
			return;
		}
		tp=tmp;
		x+=g[f][0];y+=g[f][1];
		while(map[x][y]){
			tp.ch+=cx[f];
			tp.x=x;tp.y=y;
			tp.n++;
			if(tp.n<tsum[f][x][y])
				tsum[f][x][y]=tp.n,
				q.push(tp);
			x+=g[f][0];y+=g[f][1];
		}
		tp=tmp;
		x=tmp.x;y=tmp.y;
		map[x][y]=0;
		for(int i=0;i<4;i++)
			if(i!=f&&map[x+t[i][0]][y+t[i][1]]){
				sbfs(x+t[f][0],y+t[f][1],x+t[i][0],y+t[i][1]);
				if(sn>0&&tsum[f][x][y]<tsum[i][x][y])
					tsum[i][x][y]=tsum[f][x][y],
					tp.f=i,
					tp.ch=tmp.ch+sch,
					q.push(tp);
			}
		map[x][y]=1;
	}
}
void init(){	
	printf("Maze #%d\n",++cas);
	tch="";tn=-1;
	memset(map,0,sizeof(map));
	char tmp[23];
	for(int i=1;i<=n;i++){
		scanf("%s",tmp);
		for(int j=0;j<m;j++){
			if(tmp[j]=='#') continue;
			else map[i][j+1]=1;
			if(tmp[j]=='T') tx=i,ty=j+1;
			if(tmp[j]=='B') bx=i,by=j+1;
			if(tmp[j]=='S') sx=i,sy=j+1;
		}
	}
	tbfs();
	if(tn==-1) printf("Impossible.\n");
	else cout<<tch<<endl;
	printf("\n");
}
int main(){
	while(scanf("%d%d",&n,&m)==2&&n&&m) init();
	return 0;
}