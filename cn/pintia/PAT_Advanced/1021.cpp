#include<bits/stdc++.h>
using namespace std;
vector<int> G[10001];
vector<int> tmp;
set<int> s;
bool vis[10001];
int n,maxh;
void dfs(int x,int h){
	vis[x]=1;
	if(h>maxh){
		maxh=h;
		tmp.clear();
		tmp.push_back(x);
	}else if(h==maxh){
		tmp.push_back(x);
	}
	for(int i=0;i<G[x].size();i++)
		if(!vis[G[x][i]]){
			dfs(G[x][i],h+1);
		}
}
int main() {
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int cnt=0,s1=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,1);
			if(i==1){
				if(tmp.size())s1=tmp[0];
				for(int j=0;j<tmp.size();j++)
					s.insert(tmp[j]);
			}
			cnt++;
		}
	}
    if(cnt >= 2) {
        printf("Error: %d components", cnt);
    } else {
        tmp.clear();
        maxh = 0;
        fill(vis, vis + 10010, false);
        dfs(s1, 1);
        for(int i = 0; i < tmp.size(); i++)
            s.insert(tmp[i]);
        for(auto it = s.begin(); it != s.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}