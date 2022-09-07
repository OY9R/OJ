#include<bits/stdc++.h>
using namespace std;
char maps[101][101];
int m,n,cnt=0;
void dfs(int x,int y) {
	if(maps[x][y]!='@'||x<0||y<0||x>m||y>n)
		return;
	else {
		maps[x][y]='*';
		for(int i=-1; i<=1; i++)
			for(int j=-1; j<=1; j++)
				dfs(x+i,y+j);
	}
}

int main(int argc,const char * argv[]) {
	while(scanf("%d %d",&m,&n)) {
		if(m==0||n==0)return 0;
		cnt=0;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++) {
				char c;
				do cin>>c;
				while(c!='*'&&c!='@');
				maps[i][j]=c;
			}
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				if(maps[i][j]=='@') {
					cnt++;
					dfs(i,j);
				}
		cout<<cnt<<endl;
	}
	return 0;
}