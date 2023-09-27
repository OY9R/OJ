#include<bits/stdc++.h>
using namespace std;
char a[103][103];
int n,ha,la,hb,lb;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool vis[103][103],f=0;
void dfs(int x,int y){
	if(x==hb&&y==lb){
		f=1;
		return ;
	}
	if(f) return ;
	for(int i=0;i<4;++i){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<n&&a[nx][ny]=='.'&&!vis[nx][ny]){
			vis[nx][ny]=1;
			dfs(nx,ny);
			vis[nx][ny]=0;
		}
	}
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int k;
	cin>>k;
	while(k--){
		cin>>n;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				cin>>a[i][j];
		cin>>ha>>la>>hb>>lb;
		vis[ha][la]=1;
		dfs(ha,la);
		if(a[hb][lb]=='#') printf("NO\n");
		else if(f) printf("YES\n");
		else printf("NO\n");		
		f=0;
	}
	return 0;
}