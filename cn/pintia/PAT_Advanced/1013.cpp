#include<bits/stdc++.h>
using namespace std;
const int N=1010;
vector<int> table[N];
bool visited[N];
void dfs(int cur,int oc){
	if(cur==oc||visited[cur])
		return;
	visited[cur]=true;
	for(auto t:table[cur])
		dfs(t,oc);
}
int main() {
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int f,t;
		cin>>f>>t;
		table[f].push_back(t);
		table[t].push_back(f);
	}
	if(m==0){
		cout<<n-2<<endl;
		cout<<n-2<<endl;
		return 0;
	}
	while(k--){
		int oc,cnt=0;
		cin>>oc;
		fill(visited,visited+1000,false);
		for(auto t:table[oc]){
			if(!visited[t]){
				dfs(t,oc);
				cnt++;
			}
		}
		cout<<cnt-1<<endl;
	}
	return 0;
}